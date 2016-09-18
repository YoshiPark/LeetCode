#include <vector>
using namespace std;
class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> result;
		for (auto i = 0; i <= rowIndex; ++i) {
			long long int num = 1;
			if (i == 0 || i == rowIndex) {
				result.push_back(num);
				continue;
			}
			int index = i < rowIndex - i? i : rowIndex - i;
			for (auto j = 1; j <= index; ++j) {
				num *= rowIndex - j + 1;
				num /= j;
			}
			result.push_back(num);
		}
		return result;
	}
};
