#include <iostream>
#include "Solution.h"
using namespace std;
int main() {
	string s;
	int nrows;
	cin >> s;
	cin >> nrows;
	Solution example;
	string result = example.convert(s, nrows);
	cout << result << endl;
	return 0;
}