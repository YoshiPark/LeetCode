#include <vector>
using namespace std;
class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		auto digit_s = digits;
		digit_s[digit_s.size() - 1] += 1;
		for (auto i = digit_s.size() - 1; i >= 1; --i) {
			if (digit_s[i] >= 10) {
				digit_s[i] -= 10;
				digit_s[i - 1] += 1;
			}
		}
		if (digit_s[0] >= 10) {
			digit_s.push_back(0);
			digit_s[0] = 1;
			for (auto i = 1; i < digit_s.size() - 1; ++i) digit_s[i] = 0;
		}
		return digit_s;
	}
};
