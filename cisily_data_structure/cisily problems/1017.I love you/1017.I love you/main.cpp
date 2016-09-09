#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
int main() {
	/* ifstream input("data.txt");
	if (!input) return false;
	string num_str;
	getline(input, num_str);
	int number = atoi(num_str.c_str());  */
	string num_str;
	getline(cin, num_str);
	int number = atoi(num_str.c_str());
	while (number--) {
		string daily;
		//getline(input, daily);
		getline(cin, daily);
		int m_count = 0;
		while (!daily.empty()) {
			size_t l_pos = daily.find('l');
			size_t r_pos = daily.find('r');
			if (l_pos == string::npos || r_pos == string::npos) break;
			string sub_daily = daily.substr(l_pos, r_pos - l_pos+1);
			vector<bool> judge;
			for (int i = 0; i < 9; ++i) {
				judge.push_back(false);
			}
			bool first = false;
			int fir_t = 0;
			int fir_e = 0;
			while (!sub_daily.empty()) {
				if (first == false && sub_daily[0] == 'l') {
					judge[0] = true;
					size_t u_pos = sub_daily.find('u');
					if (u_pos == string::npos) break;
					sub_daily.erase(0, u_pos);
					first = true;
				}
				else if (judge[0] = true && sub_daily[0] == 'u') {
					judge[1] = true;
					size_t v_pos = sub_daily.find('v');
					if (v_pos == string::npos) break;
					sub_daily.erase(0, v_pos);
				}
				else if (judge[1] = true && sub_daily[0] == 'v') {
					judge[2] = true;
					size_t l_pos = sub_daily.find('l');
					if (l_pos == string::npos) break;
					sub_daily.erase(0, l_pos);
				}
				else if (judge[2] = true && sub_daily[0] == 'l') {
					judge[3] = true;
					size_t e_pos = sub_daily.find('e');
					if (e_pos == string::npos) break;
					sub_daily.erase(0, e_pos);
				}
				else if (fir_e == 0 && judge[3] == true && sub_daily[0] == 'e') {
					judge[4] = true;
					size_t t_pos = sub_daily.find('t');
					if (t_pos == string::npos) break;
					sub_daily.erase(0, t_pos);
					fir_e = 1;
				}
				else if (fir_t == 0 && judge[4] == true && sub_daily[0] == 't') {
					judge[5] = true;
					size_t t_pos = sub_daily.find('t');
					if (t_pos == string::npos) break;
					sub_daily.erase(0, 1);
					fir_t = 1;
				}
				else if (judge[5] = true && sub_daily[0] == 't') {
					judge[6] = true;
					size_t e_pos = sub_daily.find('e');
					if (e_pos == string::npos) break;
					sub_daily.erase(0, e_pos);
				}
				else if (judge[6] = true && sub_daily[0] == 'e') {
					judge[7] = true;
					size_t r_pos = sub_daily.find('r');
					if (r_pos == string::npos) break;
					sub_daily.erase(0, r_pos);
				}
				else if (judge[7] = true && sub_daily[0] == 'r') {
					judge[8] = true;
					break;
				}
				else {
					sub_daily.erase(0, 1);
				}
			}
			if (judge[8] == true) m_count++;
			daily.erase(0, r_pos - l_pos + 1);
		}
		std::cout << m_count << std::endl;
	}
	return 0;
}