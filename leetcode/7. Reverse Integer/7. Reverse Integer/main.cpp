#include <iostream>
#include "Solution.h"
using namespace std;
int main() {
	int num;
	cin >> num;
	/*string s = "123456789101";
	cout << atoi(s.c_str()) << endl; */
	Solution example;
	int rev_num = example.reverse(num);
	cout << rev_num << endl;
	return 0;
}