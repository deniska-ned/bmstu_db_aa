#include <cstring>
#include <string>

#include "gtest/gtest.h"

extern "C" {
#include "levenshtein/leven_dist.h"
};

TEST(leven_iter_pos, default) {
  std::string s1{"CONNECT"};
  std::string s2{"CONEHEAD"};

  int res = levenshtein_iter(s1.c_str(), s2.c_str());

  ASSERT_EQ(4, res);
}

TEST(leven_iter_pos, empty_one) {
  std::string s1{""};
  std::string s2{"CONEHEAD"};

  int res = levenshtein_iter(s1.c_str(), s2.c_str());

  ASSERT_EQ(8, res);
}

TEST(leven_iter_pos, empty_all) {
  std::string s1{""};
  std::string s2{""};

  int res = levenshtein_iter(s1.c_str(), s2.c_str());

  ASSERT_EQ(0, res);
}

TEST(leven_iter_pos, same) {
  std::string s1{"deniska"};
  std::string s2{"deniska"};

  int res = levenshtein_iter(s1.c_str(), s2.c_str());

  ASSERT_EQ(0, res);
}

TEST(leven_iter_pos, add_first) {
  std::string s1{"abc"};
  std::string s2{"bc"};

  int res = levenshtein_iter(s1.c_str(), s2.c_str());

  ASSERT_EQ(1, res);
}
