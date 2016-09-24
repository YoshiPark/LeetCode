#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i,n=nums.size(),flag,flag1,min=99999;
        if(n==2) swap(nums[0],nums[1]);
        if(n>=3)
        {
            for(i=n-1;i>=1;i--)
            {
                if(nums[i-1]<nums[i]) break;
            }
            flag=i-1;
            if(flag!=-1)
            {
                for(i=flag+1;i<n;i++)
                {
                    if(min>nums[i]&&nums[i]>nums[flag])
                    {
                        min=nums[i];
                        flag1=i;
                    }
                }
                swap(nums[flag],nums[flag1]);
                sort(nums.begin()+flag+1,nums.end());
            }
            else
            {
                reverse(nums.begin(),nums.end());
            }
        }
      }
};
