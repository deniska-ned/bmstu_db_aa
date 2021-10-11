#include <stdbool.h>  // bool
#include <stdio.h>    // printf, fopen, fclose, fprintf
#include <stdlib.h>   // malloc, free, EXIT_FAILURE
#include <time.h>     // clock

#include "levenshtein/leven_dist.h"

#define FUNC_COUNT 4
#define ITER_COUNT 1000

double measure_time(leven_func *const fun, char const *const s1,
                    char const *const s2) {
  clock_t ts = clock();

  for (int i = 0; i < ITER_COUNT; ++i) {
    fun(s1, s2);
  }

  clock_t te = clock();

  double secs = ((double)(te - ts)) / ITER_COUNT / CLOCKS_PER_SEC;

  return secs;
}

char *get_str_by_len(size_t const len) {
  char *str = malloc(sizeof(char) * (len + 1));

  if (NULL != str) {
    for (size_t i = 0; i < len; ++i)
      if ('\0' == str[i]) str[i] = 'd';
  }

  return str;
}

void free_str(char *str) { free(str); }

int main() {
  int strlens[] = {1, 2, 4, 6, 8, 16, 32, 64, 128, 256, 512, 1024};
  size_t strlens_size = sizeof(strlens) / sizeof(strlens[0]);

  FILE *f_itr = fopen("itr.csv", "w");
  fprintf(f_itr, "strlen,leven_iter,dleven_iter\n");
  FILE *f_all = fopen("all.csv", "w");
  fprintf(f_all, "strlen,leven_rec,leven_iter,dleven_rec,dleven_iter\n");

  if (NULL == f_itr || NULL == f_all) {
    fprintf(stderr, "Failed to open file");

    if (NULL != f_all) fclose(f_all);
    if (NULL != f_itr) fclose(f_itr);

    return EXIT_FAILURE;
  }

  for (size_t i = 0; i < strlens_size; ++i) {
    char *s1 = get_str_by_len(strlens[i]);
    char *s2 = get_str_by_len(strlens[i]);

    double secs[FUNC_COUNT] = {};

    const bool run_rec = strlens[i] <= 8;

    secs[0] = run_rec ? measure_time(levenshtein_rec, s1, s2) : 0.0;
    secs[1] = measure_time(levenshtein_iter, s1, s2);
    secs[2] = run_rec ? measure_time(damerau_levenshtein_rec, s1, s2) : 0.0;
    secs[3] = measure_time(damerau_levenshtein_iter, s1, s2);

    printf("%4d, %8.2g %8.2g %8.2g %8.2g\n", strlens[i], secs[0], secs[1],
           secs[2], secs[3]);

    if (run_rec) {
      fprintf(f_all, "%d,%.3e,%.3e,%.3e,%.3e\n", strlens[i], secs[0], secs[1],
              secs[2], secs[3]);
    }
    fprintf(f_itr, "%d,%.3e,%.3e\n", strlens[i], secs[1], secs[3]);

    free_str(s2);
    free_str(s1);
  }

  fclose(f_all);
  fclose(f_itr);
}
