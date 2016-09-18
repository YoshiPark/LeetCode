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
	int target;
	cin >> target;
	Solution s;
	vector<int> two_sum = s.twoSum(nums, target);
	for (auto iter = two_sum.begin(); iter != two_sum.end(); ++iter) {
		cout << *iter << endl;
	}
	return 0;
}
