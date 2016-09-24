#include <iostream>
#include "Solution.hpp"
int main(int argc, char const *argv[]) {
  vector<int> num;
  int number;
  cin >> number;
  while (number--) {
    int temp;
    cin >> temp;
    num.push_back(temp);
  }
  int target;
  cin >> target;
  Solution example;
  auto result = example.searchRange(num, target);
  cout << result[0] << " " << result[1] << endl;
  return 0;
}
