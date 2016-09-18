#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	/* int removeElement(vector<int>& nums, int val) {
		sort(nums.begin(), nums.end());
		auto iter = find(nums.begin(), nums.end(), val);
		while (iter != nums.end()) {
			if (*iter == val) {
				iter = nums.erase(iter);
			}
			else
			{
				break;
			}
		}
		return nums.size();
	} */
	int removeElement(vector<int>& nums, int val) {
		auto iter = nums.begin();
		while (iter != nums.end()) {
			if (*iter == val) {
				iter = nums.erase(iter);
			}
			else
			{
				++iter;
			}
		}
		return nums.size();
	}
};
