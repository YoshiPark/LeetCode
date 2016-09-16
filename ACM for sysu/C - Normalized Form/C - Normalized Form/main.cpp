#include <iostream>
#include <string>
#include <stack>
#include <fstream>
using namespace std;
int main() {
	//ifstream p1("data.txt");
	string s;
	int m_count = 1;
	while (cin >> s) {
		//getline(p1, s);
		stack<char> temp;
		if (s == "()") break;
		int depth = -1;
		int top = 0;
		for (auto i = 0; i < s.length(); ++i) {
			if (s[i] == '(') ++top;
			else if (s[i] == ')') --top;
			depth = depth > top ? depth : top;
		}
		depth &= 1;
		int left_count = 0;
		for (auto i = 0; i < s.length(); ++i) {
			if (s[i] != '(' && s[i] != ')') {
				temp.push(s[i]);
			}
			else if (s[i] == '(') {
				temp.push(s[i]);
				left_count++;
			}
			else
			{
				string result;
				while (!temp.empty() && temp.top() != '(') {
					char temp_char = temp.top();
					temp.pop();
					result += temp_char;
				}
				if (left_count % 2 == depth) { // and
					if (result.find('F') != string::npos) {
						temp.pop();
						temp.push('F');
					}
					else
					{
						temp.pop();
						temp.push('T');
					}
				}
				else
				{
					if (result.find('T') == string::npos) {
						temp.pop();
						temp.push('F');
					}
					else
					{
						temp.pop();
						temp.push('T');
					}
				}
				left_count--;
			}
		}
		while (temp.top() != 'T' && temp.top() != 'F') temp.pop();
		if (temp.top() == 'T') cout << m_count << ". " << "true" << endl;
		else cout << m_count << ". " << "false" << endl;
		m_count++;
	}
	return 0;
}
