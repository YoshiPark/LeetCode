#include <iostream>
#include "Solution.h"
using namespace std;
int main() {
	int num;
	cin >> num;
	Solution s;
	cout << s.isPalindrome(num) << endl;
	return 0;
}