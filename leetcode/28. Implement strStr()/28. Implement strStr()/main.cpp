#include <iostream>
#include"Solution.h"
int main() {
	string a, b;
	cin >> a;
	cin >> b;
	Solution s;
	cout << s.strStr(a, b) << endl;
	return 0;
}