#include <iostream>
#include "Solution.h"
int main() {
	vector<int> temp;
	int num;
	cin >> num;
	for (auto i = 0; i < num; ++i) {
		int number;
		cin >> number;
		temp.push_back(number);
	}
	Solution example;
	vector<int> result = example.plusOne(temp);
	for (auto i = 0; i < result.size(); ++i) cout << result[i] << " ";
	cout << endl;
	return 0;
}