#include <vector>
#include <map>
using namespace std;
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		map<int, int> result_map;
		int result;
		for (auto iter = nums.begin(); iter != nums.end(); ++iter) {
			auto it = result_map.find(*iter);
			if ( it == result_map.end()) result_map.insert(pair<int, int>(*iter, 1));
			else it->second++;
		}
		for (auto iter = result_map.begin(); iter != result_map.end(); ++iter) {
			if (iter->second % 2 != 0) {
				result = iter->first;
				break;
			}
		}
		return result;
	}
};
