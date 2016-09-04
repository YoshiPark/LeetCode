#include <iostream>
#include "Solution.h"
using namespace std;
int main() {
	string num_str;
	cin >> num_str;
	Solution s;
	int sum = s.myAtoi(num_str);
	cout << sum << endl;
	return 0;
}