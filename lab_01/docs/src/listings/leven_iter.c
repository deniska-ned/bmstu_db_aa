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
