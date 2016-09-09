#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> result;
		auto iter = nums.begin();
		for (int i = 0; i < nums.size(); ++i) {
			++iter;
			vector<int>::iterator it = find(iter, nums.end(), target - nums[i]);
			if (it != nums.end()) {
				int pos = distance(nums.begin(), it);
				result.push_back(i);
				result.push_back(pos);
			}
		}
		return result;
	}
};
