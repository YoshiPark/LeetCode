#include <string>
using namespace std;
class Solution {
public:
	int lengthOfLastWord(string s) {
		while (s[s.length() - 1] == ' ') s = s.substr(0, s.length() - 1);
		while (s.find(' ') != string::npos) {
			auto num = s.find(' ');
			s.erase(0, num + 1);
		}
		return s.length();
	}
};
