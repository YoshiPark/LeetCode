#include "Solution.hpp"
#include <iostream>
int main() {
    int num;
    while (cin >> num) {
      vector<int> nums;
      for (auto i = 0; i < num; ++i) {
        int number;
        cin >> number;
        nums.push_back(number);
      }
      Solution s;
      int k;
      cin >> k;
      s.rotate(nums, k);
      for (auto i = 0; i < nums.size(); ++i) {
        cout << nums[i] << " ";
      }
      cout << endl;
    }
    return 0;
}
