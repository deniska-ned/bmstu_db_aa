#include <stringcmp/stringcmp.h>

#include <algorithm>
#include <future>
#include <vector>

int stringcmp(std::string const& s1, std::string const& s2) {
  auto it1 = s1.cbegin();
  auto it1_end = s1.cend();

  auto it2 = s2.cbegin();
  auto it2_end = s2.cend();

  while (it1_end != it1 && it2_end != it2 && (*it1 == *it2)) {
    ++it1;
    ++it2;
  }

  return (it1_end == it1 ? 0 : *it1) - (it2_end == it2 ? 0 : *it2);
}

int stringcmp_ll(std::string const& s1, std::string const& s2,
                 const unsigned th_num) {
  std::vector<std::future<int>> futs(th_num);

  std::size_t cmp_len = std::min(s1.size(), s2.size());

  int offset = 0;
  unsigned min_per_th = cmp_len / th_num;
  unsigned extra = cmp_len % th_num;

  for (unsigned i = 0; i < th_num; ++i) {
    auto it1 = s1.cbegin() + offset;
    auto it2 = s2.cbegin() + offset;

    offset += min_per_th + (extra > 0 ? 1 : 0);

    auto it1_end = s1.cbegin() + offset;
    auto it2_end = s2.cbegin() + offset;

    --extra;

    futs[i] = std::async(
        std::launch::async,
        [](auto it1, auto it1_end, auto it2, auto it2_end) -> int {
          while (it1_end != it1 && it2_end != it2 && (*it1 == *it2)) {
            ++it1;
            ++it2;
          }

          return (it1_end == it1 ? 0 : *it1) - (it2_end == it2 ? 0 : *it2);
        },
        it1, it1_end, it2, it2_end);
  }

  int res = 0;
  for (unsigned i = 0; i < th_num && res == 0; res = futs[i].get(), ++i) {
  }

  return res;
}
