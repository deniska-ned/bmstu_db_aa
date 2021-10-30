#include <chrono>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

#include "stringcmp/stringcmp.h"

void test_time_by_th_num() {
  std::vector<unsigned> th_nums = {1, 2, 4, 8, 16, 32, 64};
  std::vector<unsigned> strlens = {1048576,   2097152,  4194304,  8388608,
                                   16777216,  33554432, 67108864, 134217728,
                                   268435456, 536870912};

  std::ofstream f("time_by_th_num.csv");

  f << "strsize_mb";
  for (auto th_num : th_nums) {
    f << ',' << "th_num_" << th_num;
  }
  f << std::endl;

  for (auto len : strlens) {
    f << len / 1'048'576;

    std::string str(len, 'D');

    for (auto th_num : th_nums) {
      auto start = std::chrono::system_clock::now();
      stringcmp_ll(str, str, th_num);
      auto end = std::chrono::system_clock::now();

      f << ','
        << std::chrono::duration_cast<std::chrono::milliseconds>(end - start)
               .count();
    }

    f << std::endl;
  }
}

void test_time_by_algorithm() {
  std::vector<unsigned> strlens = {1048576,   2097152,  4194304,  8388608,
                                   16777216,  33554432, 67108864, 134217728,
                                   268435456, 536870912};

  std::ofstream f("time_by_algorithm.csv");

  f << "strsize_mb,parallel,nonparallel" << std::endl;

  for (auto len : strlens) {
    f << len / 1'048'576;

    std::string str(len, 'D');

    auto start = std::chrono::system_clock::now();
    stringcmp_ll(str, str);
    auto end = std::chrono::system_clock::now();
    f << ','
      << std::chrono::duration_cast<std::chrono::milliseconds>(end - start)
             .count();

    start = std::chrono::system_clock::now();
    stringcmp(str, str);
    end = std::chrono::system_clock::now();
    f << ','
      << std::chrono::duration_cast<std::chrono::milliseconds>(end - start)
             .count();
    f << std::endl;
  }

  f << std::endl;
}

int main() {
  test_time_by_th_num();
  test_time_by_algorithm();
}
