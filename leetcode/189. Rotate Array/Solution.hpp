#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    void rotate_part(vector<int>& nums, int start, int end) {
      for (int i = start; i < (start + end) / 2; ++i) {
        int temp = nums[i];
        nums[i] = nums[end - 1 - i + start];
        nums[end - 1 - i + start] = temp;
      }
    }
    void rotate(vector<int>& nums, int k) {
        if (k >= nums.size()) k %= nums.size();
        rotate_part(nums, 0, nums.size() - k);
        /*for (auto i = 0; i < nums.size(); ++i) {
          cout << nums[i] << " ";
        }
        cout << endl; */
        rotate_part(nums, nums.size()-k, nums.size());
        /* for (auto i = 0; i < nums.size(); ++i) {
          cout << nums[i] << " ";
        }
        cout << endl; */
        rotate_part(nums, 0, nums.size());
    }
};
