#include <iostream>
#include "Solution.h"
using namespace std;
int main() {
	int number;
	cin >> number;
	Solution example;
	cout << example.climbStairs(number) << endl;
	return 0;
}