#include <iostream>
#include "Solution.hpp"
int main() {
  while (true) {
    int num;
    cin >> num;
    Solution example;
    auto result = example.generateParenthesis(num);
    for (auto i = 0; i < result.size(); ++i) {
      cout << result[i] << endl;
    }
  }
  return 0;
}
