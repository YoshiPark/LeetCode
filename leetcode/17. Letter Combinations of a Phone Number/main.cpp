#include <iostream>
#include "Solution.hpp"
using namespace std;
int main() {
    while (true) {
      string s;
      cin >> s;
      Solution example;
      auto result = example.letterCombinations(s);
      for (auto i = 0; i < result.size(); ++i) {
        cout << result[i] << endl;
      }
    }
    return 0;
}
