#pragma once

#include <string>
#include <thread>

int stringcmp(std::string const& s1, std::string const& s2);

int stringcmp_ll(
    std::string const& s1, std::string const& s2,
    const unsigned thread_num = []() {
      unsigned th_num = std::thread::hardware_concurrency();
      return th_num ? th_num : 2;
    }());

