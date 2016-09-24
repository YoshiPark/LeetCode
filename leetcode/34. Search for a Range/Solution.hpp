#include <vector>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        int pos = nums.size() / 2;
        if (target < nums[pos]) {
          bool end_pos = false;
          for (int i = pos-1; i >= 0; --i) {
            if (nums[i] == target && end_pos == false) {
              result.push_back(i);
              end_pos = true;
            }
            else if (nums[i] < target && nums[i+1] == target) {
              result.push_back(i+1);
              break;
            }
            else if (i == 0 && nums[i] == target) result.push_back(i);
          }
        }
        else if (target == nums[pos]) {
          int temp = 1;
          bool start = false, end = false;
          while (true) {
            if (nums[pos-temp] != target && start == false) {
              result.push_back(pos-temp + 1);
              start = true;
            }
            if (nums[pos+temp] != target && end == false) {
              result.push_back(pos+temp - 1);
              end = true;
            }
            temp++;
            if (end == true && start == true) break;
          }
        }
        else {
          int len = nums.size();
          bool start_pos = false;
          for (auto i = pos + 1; i < len; ++i) {
            if (nums[i] == target && start_pos == false) {
              result.push_back(i);
              start_pos = true;
            }
            else if (nums[i] > target && nums[i-1] == target) {
              result.push_back(i-1);
              break;
            }
            else if (i == len - 1 && nums[i] == target) result.push_back(i);
          }
        }
        if (result.size() == 0) {
          result.push_back(-1);
          result.push_back(-1);
        }
        else if (result.size() == 1) {
            result.push_back(result[0]);
        }
        if (result[0] > result[1]) swap(result[0],result[1]);
        return result;
    }
};
