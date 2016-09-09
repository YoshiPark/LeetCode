#include <string>
#include <sstream>
#include <limits> 
using namespace std;
class Solution {
public:
	string int_2_string(int x) {
		string result;
		stringstream ss;
		ss << x;
		ss >> result;
		return result;
	}
	int reverse(int x) {
		string INT_MAX_str = "2147483647";
		string INT_MIN_str = "2147483648";
		string filter = int_2_string(x);
		if (x >= 0) {
			string result;
			for (int i = filter.size() - 1; i >= 0; --i) {
				result += filter[i];
			}
			if (result.length() == 10) {
				for (int i = 0; i < result.length(); ++i) {
					if (result[i] < INT_MAX_str[i]) break;
					if (result[i] > INT_MAX_str[i]) {
						return 0;
					}
				}
			}
			return atoi(result.c_str());
		}
		else
		{
			filter.erase(0, 1);
			string result;
			for (int i = filter.size() - 1; i >= 0; --i) {
				result += filter[i];
			}
			if (result.length() == 10) {
				for (int i = 0; i < result.length(); ++i) {
					if (result[i] < INT_MIN_str[i]) break;
					if (result[i] > INT_MIN_str[i]) {
						return 0;
					}
				}
			}
			result = "-" + result;
			return atoi(result.c_str());
		}
	}
};
