#include <iostream>
#include "Solution.hpp"
int main() {
  while (true) {
    int n, m;
    cin >> n >> m;
    Solution example;
    cout << example.divide(n, m) << endl;
  }

  return 0;
}
