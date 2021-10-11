#ifndef LEVEL_DIST_H
#define LEVEL_DIST_H

int levenshtein_rec(char const *const s1, char const *const s2);

int levenshtein_iter(char const *const s1, char const *const s2);

int damerau_levenshtein_rec(char const *const s1, char const *const s2);

int damerau_levenshtein_iter(char const *const s1, char const *const s2);

#endif  // LEVEL_DIST_H
