#include <iostream>
#include <string>
#include <sstream>
using namespace std;
class Solution {
public:
	string int_2_string(int num) {
		string result;
		stringstream ss;
		ss << num;
		ss >> result;
		return result;
	}
	bool isPalindrome(int x) {
		string filter = int_2_string(x);
		for (int i = 0; i < filter.length() / 2; ++i) {
			if (filter[i] != filter[filter.length() - 1 - i]) return false;
		}
		return true;
	}
};
