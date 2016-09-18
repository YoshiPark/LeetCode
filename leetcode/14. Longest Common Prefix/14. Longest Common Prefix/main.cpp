#include <iostream>
#include "Solution.h"
using namespace std;
int main() {
	vector<string> str;
	int num;
	cin >> num;
	for (auto i = 0; i < num; ++i) {
		string temp;
		cin >> temp;
		str.push_back(temp);
	}
	Solution s;
	string result = s.longestCommonPrefix(str);
	cout << result << endl;
	return 0;
}