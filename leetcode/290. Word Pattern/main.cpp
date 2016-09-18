#include <iostream>
#include "Solution.hpp"
int main() {
  while (true) {
    string s,t;
    getline(cin,s);
    getline(cin,t);
    Solution example;
    cout << example.wordPattern(s, t) << endl;
  }
  return 0;
}
