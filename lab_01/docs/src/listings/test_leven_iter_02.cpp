TEST(leven_iter_pos, add_mid) {
  std::string s1{"abc"};
  std::string s2{"ac"};

  int res = levenshtein_iter(s1.c_str(), s2.c_str());

  ASSERT_EQ(1, res);
}

TEST(leven_iter_pos, add_last) {
  std::string s1{"abc"};
  std::string s2{"ab"};

  int res = levenshtein_iter(s1.c_str(), s2.c_str());

  ASSERT_EQ(1, res);
}

TEST(leven_iter_pos, replace_first) {
  std::string s1{"abc"};
  std::string s2{"xbc"};

  int res = levenshtein_iter(s1.c_str(), s2.c_str());

  ASSERT_EQ(1, res);
}

TEST(leven_iter_pos, replace_mid) {
  std::string s1{"abc"};
  std::string s2{"axc"};

  int res = levenshtein_iter(s1.c_str(), s2.c_str());

  ASSERT_EQ(1, res);
}

TEST(leven_iter_pos, replace_last) {
  std::string s1{"abc"};
  std::string s2{"abx"};

  int res = levenshtein_iter(s1.c_str(), s2.c_str());

  ASSERT_EQ(1, res);
}
