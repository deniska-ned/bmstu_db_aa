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
