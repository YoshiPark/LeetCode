#include <iostream>
#include "Solution.hpp"
int main() {
  string temp1, temp2;
  while (cin >> temp1 >> temp2) {
    Solution s;
    cout << s.compareVersion(temp1, temp2) << endl;
  }
}
