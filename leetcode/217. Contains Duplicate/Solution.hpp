#include <vector>
#include <set>
using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if (nums.empty()) return false;
        set<int> result;
        for (auto i = 0; i < nums.size(); ++i) result.insert(nums[i]);
        return result.size() != nums.size();
    }
};
