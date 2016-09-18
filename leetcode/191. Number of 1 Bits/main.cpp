#include <iostream>
#include "Solution.hpp"
using namespace std;
int main() {
    uint32_t n;
    while (cin >> n) {
      Solution s;
      cout << s.hammingWeight(n) << endl;
    }
    return 0;
}
