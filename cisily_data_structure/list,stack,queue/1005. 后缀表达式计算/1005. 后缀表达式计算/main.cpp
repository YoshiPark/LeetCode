#include <iostream>
#include <string>
#include <stack>
#include <iomanip>
using namespace std;
class Solution {
public:
	double last_2_num(string num_str) {
		stack<double> num;
		while (!num_str.empty()) {
			if (num_str[0] >= 'a' && num_str[0] <= 'z') {
				num.push(num_str[0] - 'a' + 1);
				num_str.erase(0, 1);
			}
			else
			{
				if (num_str[0] == '+') {
					if (num.size() >= 2) {
						double num_1 = num.top();
						num.pop();
						double num_2 = num.top();
						num.pop();
						double num_all = num_1 + num_2;
						num.push(num_all);
					}
				}
				else if (num_str[0] == '-') {
					if (num.size() >= 2) {
						double num_1 = num.top();
						num.pop();
						double num_2 = num.top();
						num.pop();
						double num_all = num_2 - num_1;
						num.push(num_all);
					}
				}
				else if (num_str[0] == '*')
				{
					double num_1 = num.top();
					num.pop();
					double num_2 = num.top();
					num.pop();
					double num_all = num_1 * num_2;
					num.push(num_all);
				}
				else
				{
					double num_1 = num.top();
					num.pop();
					double num_2 = num.top();
					num.pop();
					double num_all = num_2 / num_1;
					num.push(num_all);
				}
				num_str.erase(0, 1);
			}
		}
		double result = num.top();
		num.pop();
		return result;
	}
};
int main() {
	int num;
	cin >> num;
	while (num--) {
		string temp;
		cin >> temp;
		Solution s;
		cout << fixed << setprecision(2) << s.last_2_num(temp) << endl;
	}
	return 0;
}