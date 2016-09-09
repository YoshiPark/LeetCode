#include <iostream>
#include "Solution.h"
using namespace std;
int main() {
	vector<int> nums;
	int times;
	cin >> times;
	for (auto i = 0; i < times; ++i) {
		int num;
		cin >> num;
		nums.push_back(num);
	}
	Solution s;
	cout << s.removeDuplicates(nums) << endl;
	return 0;
}