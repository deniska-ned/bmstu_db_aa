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
