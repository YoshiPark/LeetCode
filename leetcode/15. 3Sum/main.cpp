#include <iostream>
#include <fstream>
#include <string>
#include "Solution.hpp"
int main() {
  ifstream p1("data.txt");
  string s;
  while (!p1.eof()) {
    std::vector<int> v;
    getline(p1,s);
    while (!s.empty()) {
      auto pos = s.find(",");
      string sub_s = s.substr(0, pos);
      int number = atoi(sub_s.c_str());
      v.push_back(number);
      s.erase(0, pos+1);
    }
    Solution example;
    auto result = example.threeSum(v);
    for (auto i = 0; i < result.size(); ++i) {
      for (auto j = 0; j < result[i].size(); ++j) {
        cout << result[i][j] << " ";
      }
      cout << endl;
    }
  }
  return 0;
}
