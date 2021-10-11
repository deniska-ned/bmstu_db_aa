static int levenshtein_rec_(char const *const s1, char const *const s2,
                            int const i, int const j) {
  int res = 0;

  if (0 == i || 0 == j) {
    res = abs(i - j);
  } else {
    int eq = 0;

    if (s1[i - 1] != s2[j - 1]) eq = 1;

    res = min_int(levenshtein_rec_(s1, s2, i - 1, j) + 1,
                  min_int(levenshtein_rec_(s1, s2, i, j - 1) + 1,
                          levenshtein_rec_(s1, s2, i - 1, j - 1) + eq));
  }

  return res;
}

int levenshtein_rec(char const *const s1, char const *const s2) {
  return levenshtein_rec_(s1, s2, strlen(s1), strlen(s2));
}
