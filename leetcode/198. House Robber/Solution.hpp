#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        int a[2] = {0};
        a[0] = 0;
        a[1] = nums[0];
        for (size_t i = 1; i < nums.size(); ++i) {
            int temp = a[0];
            a[0] = max(a[0], a[1]);
            a[1] = temp + nums[i];
        }
        return a[0] > a[1] ? a[0] : a[1];
    }
};
