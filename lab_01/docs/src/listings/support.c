static inline int min_int(const int l, const int r) { return l <= r ? l : r; }

static inline void swp_pint(int **p1, int **p2) {
  void *bucket = *p1;
  *p1 = *p2;
  *p2 = bucket;
}
