#include <iostream>
#include "Solution.h"
#include <fstream>
int main() {
	fstream f1("data.txt");
	string a, b;
	getline(f1, a);
	getline(f1, b);
	Solution s;
	cout << s.addBinary(a, b) << endl;
	return 0;
}