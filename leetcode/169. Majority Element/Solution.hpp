#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> number;
        for (auto i = 0; i < nums.size(); ++i) {
          auto iter = number.find(nums[i]);
          if (iter != number.end()) {
            iter->second++;
          } else {
            number.insert(pair<int,int>(nums[i],1));
          }
        }
        for (auto iter = number.begin(); iter != number.end(); ++iter) {
          if (iter->second > nums.size()/2) return iter->first;
        }
        return 0;
    }
};
