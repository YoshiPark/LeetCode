#include <iostream>
#include <map>
using namespace std;
int main() {
	int num;
	cin >> num;
	while (num--) {
		map<int, int> num_1;
		map<int, int> num_2;
		int num_pol_1, num_pol_2;
		cin >> num_pol_1;
		for (int i = 0; i < num_pol_1; ++i) {
			int coef;
			int exp;
			cin >> coef;
			cin >> exp;
			num_1.insert(pair<int, int>(exp, coef));
		}
		cin >> num_pol_2;
		for (int j = 0; j < num_pol_2; ++j) {
			int coef;
			int exp;
			cin >> coef;
			cin >> exp;
			num_2.insert(pair<int, int>(exp, coef));
		}
		map<int, int> num_3;
		while (!num_1.empty()) {
			map<int, int>::iterator iter = num_1.begin();
			map<int, int>::iterator it = num_2.begin();
			while (it != num_2.end()) {
				if (it->first == iter->first) {
					break;
				}
				else
				{
					it++;
				}
			}
			if (it != num_2.end()) {
				int exp = iter->first;
				int coef = iter->second + it->second;
				num_3.insert(pair<int, int>(exp, coef));
				num_1.erase(iter);
				num_2.erase(it);
			}
			else
			{
				int exp = iter->first;
				int coef = iter->second;
				num_3.insert(pair<int, int>(exp, coef));
				num_1.erase(iter);
			}

		}
		while (!num_2.empty()) {
			map<int, int>::iterator iter = num_2.begin();
			int exp = iter->first;
			int coef = iter->second;
			num_3.insert(pair<int, int>(exp, coef));
			num_2.erase(iter);
		}
		int m_count = 0;
		for (map<int, int>::reverse_iterator iter = num_3.rbegin(); iter != num_3.rend(); ++iter) {
			if (iter->second != 0) {
				m_count++;
			}
		}
		cout << m_count << endl;
		for (map<int, int>::reverse_iterator iter = num_3.rbegin(); iter != num_3.rend(); ++iter) {
			if (iter->second != 0) {
				cout << iter->second << " " << iter->first << endl;
			}
		}
	}
	return 0;
}