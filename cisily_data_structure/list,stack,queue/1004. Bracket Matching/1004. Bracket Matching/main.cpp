#include <stack>
#include <string>
#include <iostream>
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
int main() {
	int num;
	cin >> num;
	while (num--) {
		string temp;
		cin >> temp;
		Solution s;
		if (s.isValid(temp)) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}