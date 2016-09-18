#include "Solution.h"
int main() {
	vector<int> nums;
	int num;
	cin >> num;
	while (num--) {
		nums.push_back(num);
	}
	Solution example;
	vector<vector<int>> result = example.subsets(nums);
	for (auto i = 0; i < result.size(); ++i) {
		cout << "[";
		for (auto j = 0; j < result[i].size(); ++j) {
			cout << result[i][j];
			if (j != result[i].size() - 1) cout << ",";
		}
		cout << "]" << endl;
	}
	return 0;
}