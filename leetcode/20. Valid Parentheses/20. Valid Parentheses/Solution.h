#include <stack>
#include <string>
using namespace std;
class Solution {
public:
	bool isValid(string s) {
		stack<char> judge;
		for (auto i = 0; i < s.length(); ++i) {
			if (s[i] == '{' || s[i] == '[' || s[i] == '(') {
				judge.push(s[i]);
			}
			else if (s[i] == '}') {
				if (judge.empty()) return false;
				char temp = judge.top();
				if (temp == '{') {
					judge.pop();
				}
				else
				{
					return false;
				}
			}
			else if (s[i] == ']') {
				if (judge.empty()) return false;
				char temp = judge.top();
				if (temp == '[') {
					judge.pop();
				}
				else
				{
					return false;
				}
			}
			else if (s[i] == ')') {
				if (judge.empty()) return false;
				char temp = judge.top();
				if (temp == '(') {
					judge.pop();
				}
				else
				{
					return false;
				}
			}
		}
		if (!judge.empty()) return false;
		return true;
	}
};
