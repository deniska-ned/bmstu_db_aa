#include <string>  // std::string

#include "gtest/gtest.h"

extern "C" {
#include "levenshtein/leven_dist.h"
};

TEST(damerau_leven_rec_pos, default) {
  std::string s1{"CONNECT"};
  std::string s2{"CNNNETC"};

  int res = damerau_levenshtein_rec(s1.c_str(), s2.c_str());

  ASSERT_EQ(2, res);
}

TEST(damerau_leven_rec_pos, empty_one) {
  std::string s1{""};
  std::string s2{"CONEHEAD"};

  int res = damerau_levenshtein_rec(s1.c_str(), s2.c_str());

  ASSERT_EQ(8, res);
}

TEST(damerau_leven_rec_pos, empty_all) {
  std::string s1{""};
  std::string s2{""};

  int res = damerau_levenshtein_rec(s1.c_str(), s2.c_str());

  ASSERT_EQ(0, res);
}

TEST(damerau_leven_rec_pos, same) {
  std::string s1{"deniska"};
  std::string s2{"deniska"};

  int res = damerau_levenshtein_rec(s1.c_str(), s2.c_str());

  ASSERT_EQ(0, res);
}

TEST(damerau_leven_rec_pos, add_first) {
  std::string s1{"abc"};
  std::string s2{"bc"};

  int res = damerau_levenshtein_rec(s1.c_str(), s2.c_str());

  ASSERT_EQ(1, res);
}

TEST(damerau_leven_rec_pos, add_mid) {
  std::string s1{"abc"};
  std::string s2{"ac"};

  int res = damerau_levenshtein_rec(s1.c_str(), s2.c_str());

  ASSERT_EQ(1, res);
}

TEST(damerau_leven_rec_pos, add_last) {
  std::string s1{"abc"};
  std::string s2{"ab"};

  int res = damerau_levenshtein_rec(s1.c_str(), s2.c_str());

  ASSERT_EQ(1, res);
}

TEST(damerau_leven_rec_pos, replace_first) {
  std::string s1{"abc"};
  std::string s2{"xbc"};

  int res = damerau_levenshtein_rec(s1.c_str(), s2.c_str());

  ASSERT_EQ(1, res);
}

TEST(damerau_leven_rec_pos, replace_mid) {
  std::string s1{"abc"};
  std::string s2{"axc"};

  int res = damerau_levenshtein_rec(s1.c_str(), s2.c_str());

  ASSERT_EQ(1, res);
}

TEST(damerau_leven_rec_pos, replace_last) {
  std::string s1{"abc"};
  std::string s2{"abx"};

  int res = damerau_levenshtein_rec(s1.c_str(), s2.c_str());

  ASSERT_EQ(1, res);
}

TEST(damerau_leven_rec_pos, trans_2) {
  std::string s1{"abcd"};
  std::string s2{"badc"};

  int res = damerau_levenshtein_rec(s1.c_str(), s2.c_str());

  ASSERT_EQ(2, res);
}
