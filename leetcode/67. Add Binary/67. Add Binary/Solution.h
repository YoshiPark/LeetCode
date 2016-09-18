#include <string>
#include <cmath>
using namespace std;
class Solution {
public:
	string addBinary(string a, string b) {
		int a_array[1000] = { 0 }, b_array[1000] = { 0 }, c_array[1000] = { 0 };
		for (int i = a.length() - 1, j = 0; i >= 0; --i, ++j) a_array[j] = a[i] - '0';
		for (int i = b.length() - 1, j = 0; i >= 0; --i, ++j) b_array[j] = b[i] - '0';
		int min_ = a.length() > b.length() ? b.length() : a.length();
		int max_ = a.length() > b.length() ? a.length() : b.length();
		for (auto i = 0; i < min_; ++i) {
			c_array[i] += a_array[i] + b_array[i];
			if (c_array[i] >= 2) {
				c_array[i + 1] += 1;
				c_array[i] -= 2;
			}
		}
		if (min_ == a.length()) {
			for (auto i = min_; i < b.length(); ++i) {
				c_array[i] += b_array[i];
				if (c_array[i] >= 2) {
					c_array[i + 1] += 1;
					c_array[i] -= 2;
				}
			}
		}
		else
		{
			for (auto i = min_; i < a.length(); ++i) {
				c_array[i] += a_array[i];
				if (c_array[i] >= 2) {
					c_array[i + 1] += 1;
					c_array[i] -= 2;
				}
			}
		}
		string result;
		for (auto i = max_; i >= 0; --i) {
			if (i < max_)result += c_array[i] + '0';
			else
			{
				if (c_array[i] == 1) result += c_array[i] + '0';
			}
		}
		return result;
	}
	/*string addBinary(string a, string b)
    {
        string s = "";
        
        int c = 0, i = a.size() - 1, j = b.size() - 1;
        while(i >= 0 || j >= 0 || c == 1)
        {
            c += i >= 0 ? a[i --] - '0' : 0;
            c += j >= 0 ? b[j --] - '0' : 0;
            s = char(c % 2 + '0') + s;
            c /= 2;
        }
        
        return s;
    }
	
	*/
};
