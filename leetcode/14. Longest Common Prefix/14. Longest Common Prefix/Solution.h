#include <string>
#include <vector>
using namespace std;
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.size() == 0) return "";
		int min = 1000;
		int pos = 0;
		for (auto i = 0; i < strs.size(); ++i) {
			if (strs[i].length() < min) {
				min = strs[i].length();
				pos = i;
			}
		}
		string str_min = strs[pos];
		auto iter = strs.begin();
		while (iter != strs.end()) {
			int min_pos = 0;
			for (auto i = 0; i < (*iter).length(); ++i) {
				if (str_min[i] != (*iter)[i]) {
					str_min = (*iter).substr(0, min_pos);
					break;
				}
				min_pos++;
			}
			iter++;
		}
		return str_min;
	}
};
