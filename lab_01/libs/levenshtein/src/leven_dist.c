#include "levenshtein/leven_dist.h"

#include <stdlib.h>  // abs, malloc, free
#include <string.h>  // strlen

static inline int min_int(const int l, const int r) { return l <= r ? l : r; }

static inline void swp_pint(int **p1, int **p2) {
  void *bucket = *p1;
  *p1 = *p2;
  *p2 = bucket;
}

int levenshtein_rec(char const *const s1, char const *const s2, int const i,
                    int const j) {
  int res = 0;

  if (0 == i || 0 == j) {
    res = abs(i - j);
  } else {
    int eq = 0;

    if (s1[i - 1] != s2[j - 1]) eq = 1;

    res = min_int(levenshtein_rec(s1, s2, i - 1, j) + 1,
                  min_int(levenshtein_rec(s1, s2, i, j - 1) + 1,
                          levenshtein_rec(s1, s2, i - 1, j - 1) + eq));
  }

  return res;
}

int levenshtein_iter(char const *const s1, char const *const s2) {
  size_t l1 = strlen(s1);
  size_t l2 = strlen(s2);

  int *prev = malloc((l1 + 1) * sizeof(int));
  int *curr = malloc((l1 + 1) * sizeof(int));

  if (NULL == prev || NULL == curr) {
    if (NULL != prev) free(prev);
    if (NULL != curr) free(curr);

    return -1;
  }

  for (size_t i = 0; i <= l1; ++i) prev[i] = i;

  for (size_t i = 1; i <= l2; ++i) {
    curr[0] = i;

    for (size_t j = 1; j <= l1; ++j) {
      int eq = 0;

      if (s1[j - 1] != s2[i - 1]) eq = 1;

      curr[j] =
          min_int(curr[j - 1] + 1, min_int(prev[j - 1] + eq, prev[j] + 1));
    }

    swp_pint(&prev, &curr);
  }

  int res = prev[l1];

  free(curr);
  free(prev);

  return res;
}

int damerau_levenshtein_rec(char const *const s1, char const *const s2,
                            int const i, int const j) {
  int res = 0;

  if (0 == i || 0 == j) {
    res = abs(i - j);
  } else {
    int eq = 0;

    if (s1[i - 1] != s2[j - 1]) eq = 1;

    res = min_int(damerau_levenshtein_rec(s1, s2, i - 1, j) + 1,
                  min_int(damerau_levenshtein_rec(s1, s2, i, j - 1) + 1,
                          damerau_levenshtein_rec(s1, s2, i - 1, j - 1) + eq));

    if (i > 1 && j > 1 && s1[i - 1] == s2[j - 2] && s1[i - 2] == s2[j - 1]) {
      res = min_int(res, damerau_levenshtein_rec(s1, s2, i - 2, j - 2) + 1);
    }
  }

  return res;
}

int damerau_levenshtein_iter(char const *const s1, char const *const s2) {
  size_t l1 = strlen(s1);
  size_t l2 = strlen(s2);

  int *pre2 = malloc((l1 + 1) * sizeof(int));
  int *pre1 = malloc((l1 + 1) * sizeof(int));
  int *curr = malloc((l1 + 1) * sizeof(int));

  if (NULL == pre2 || NULL == pre1 || NULL == curr) {
    if (NULL != pre2) free(pre2);
    if (NULL != pre1) free(pre1);
    if (NULL != curr) free(curr);

    return -1;
  }

  for (size_t i = 0; i <= l1; ++i) pre1[i] = i;

  for (size_t i = 1; i <= l2; ++i) {
    curr[0] = i;

    for (size_t j = 1; j <= l1; ++j) {
      int eq = 0;

      if (s1[j - 1] != s2[i - 1]) eq = 1;

      curr[j] =
          min_int(curr[j - 1] + 1, min_int(pre1[j - 1] + eq, pre1[j] + 1));

      if (i > 1 && j > 1 && s1[i - 1] == s2[j - 2] && s1[i - 2] == s2[j - 1]) {
        curr[j] = min_int(curr[j], pre2[j - 2] + 1);
      }
    }

    swp_pint(&pre2, &pre1);
    swp_pint(&pre1, &curr);
  }

  int res = pre1[l1];

  free(curr);
  free(pre1);
  free(pre2);

  return res;
}
