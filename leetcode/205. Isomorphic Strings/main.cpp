#include <iostream>
#include "Solution.hpp"
int main() {
  string s,t;
  while (cin >> s >> t) {
    Solution example;
    cout << example.isIsomorphic(s, t) << endl;
  }
  return 0;
}
