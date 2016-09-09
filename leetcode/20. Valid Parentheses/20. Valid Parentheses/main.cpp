#include <iostream>
#include "Solution.h"
using namespace std;
int main() {
	string s;
	while (true) {
		cin >> s;
		Solution example;
		cout << example.isValid(s) << endl;
	}

	return 0;
}