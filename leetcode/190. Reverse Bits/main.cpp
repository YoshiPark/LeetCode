#include <iostream>
#include "Solution.hpp"
using namespace std;
int main() {
  uint32_t t;
  while (cin >> t) {
    Solution s;
    cout << s.reverseBits(t) << endl;
  }
  return 0;
}
