#include <vector>
using namespace std;
class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> result;
		if (numRows == 0) return result;
		vector<int> first_row, second_row;
		first_row.push_back(1);
		for (auto i = 0; i < 2; ++i) second_row.push_back(1);
		result.push_back(first_row);
		if (numRows == 1)return result;
		result.push_back(second_row);
		if (numRows == 2) return result;
		for (auto i = 3; i <= numRows; ++i) {
			vector<int> temp;
			for (auto j = 0; j < i; ++j) temp.push_back(0);
			result.push_back(temp);
		}
		for (auto i = 2; i < numRows; ++i) {
			for (auto j = 0; j <= i; ++j) {
				if (j == 0 || j == i) result[i][j] = 1;
				else result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
			}
		}
		return result;
	}
};
