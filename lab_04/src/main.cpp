#include <iostream>
#include <string>

#include "stringcmp/stringcmp.h"

int main() {
  std::string s1, s2;

  std::cout << "Enter 2 strings:" << std::endl;
  std::cin >> s1 >> s2;

  int res = stringcmp(s1, s2);
  int res_ll = stringcmp_ll(s1, s2);

  std::cout << "res          = " << res << std::endl;
  std::cout << "res parallel = " << res_ll << std::endl;
}
