#include <iostream>
#include "Solution.hpp"
int main() {
  std::vector<int> v;
  int num;
  cin >> num;
  while (num--) {
    int number;
    cin >>number;
    v.push_back(number);
  }
  Solution example;
  int target;
  cin >> target;
  cout << example.threeSumClosest(v, target) << endl;
  return 0;
}
