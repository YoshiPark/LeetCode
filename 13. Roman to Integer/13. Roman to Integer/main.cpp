#include <iostream>
#include "Solution.h"
using namespace std;
int main()  {
	string s;
	while (true) {
		cin >> s;
		Solution example;
		cout << example.romanToInt(s) << endl;
	}
	
	return 0;
}