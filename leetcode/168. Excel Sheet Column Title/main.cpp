#include <iostream>
#include "Solution.hpp"
int main() {
  int num;
  while (cin >> num) {
    Solution s;
    cout << s.convertToTitle(num) << endl;
  }
  return 0;
}
