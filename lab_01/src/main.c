#include <stdio.h>   // printf, getline
#include <stdlib.h>  // free
#include <string.h>  // strlen

#include "levenshtein/leven_dist.h"

int main(void) {
  char *s1 = NULL, *s2 = NULL;
  size_t l1 = 0, l2 = 0;

  int rc = 0;

  printf("Enter line 1: ");
  if (-1 == (rc = getline(&s1, &l1, stdin))) {
    printf("Allocation failed");
    s1 = NULL;
  } else {
    printf("Enter line 2: ");
    if (-1 == (rc = getline(&s2, &l2, stdin))) {
      printf("Allocation failed");
    } else {
      s1[strlen(s1) - 1] = '\0';
      s2[strlen(s2) - 1] = '\0';

      int res_lr = levenshtein_rec(s1, s2);
      printf("LR  ('%s', '%s') = %d\n", s1, s2, res_lr);

      int res_li = levenshtein_iter(s1, s2);
      printf("LI  ('%s', '%s') = %d\n", s1, s2, res_li);

      int res_dlr = damerau_levenshtein_rec(s1, s2);
      printf("DLR ('%s', '%s') = %d\n", s1, s2, res_dlr);

      int res_dli = damerau_levenshtein_iter(s1, s2);
      printf("DLI ('%s', '%s') = %d\n", s1, s2, res_dli);

      free(s2);
      s2 = NULL;
    }
    free(s1);
    s1 = NULL;
  }
}
