#include <iostream>
#include "Solution.hpp"
int main() {
    while (true) {
      string s;
      cin >> s;
      Solution example;
      cout << example.longestPalindrome(s) << endl;
    }
    return 0;
}
