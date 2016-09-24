#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums, int target) {
      sort(nums.begin(),nums.end());
      int i,j,k,len;
      vector<vector<int>> result;
      len = nums.size();
      if(len<3)   return {};
      for(i=0;i<=len-3;++i){
          if(i!=0&&nums[i-1]==nums[i])
              continue;
          j = i + 1;
          k = len - 1;
          while(j<k){
              if(nums[j]+nums[i]+nums[k]<target)   j++;
              else if(nums[j]+nums[i]+nums[k]==target){
                  result.push_back({nums[i],nums[j],nums[k]});
                  j++;
                  k--;
                  while(j<k&&nums[j-1]==nums[j]) j++;
                  while(j<k&&nums[k+1]==nums[k]) k--;
              }
              else    k--;
          }
      }
      return result;
  }
    int threeSumClosest(vector<int>& nums, int target) {
        int pos = 0;
        auto result = threeSum(nums, target);
        if (!result.empty()) return target;
        pos++;
        while (true) {
          auto result1 = threeSum(nums, target + pos);
          if (!result1.empty()) return target + pos;
          auto result2 = threeSum(nums, target - pos);
          if (!result2.empty()) return target - pos;
          pos++;
        }
    }
};
