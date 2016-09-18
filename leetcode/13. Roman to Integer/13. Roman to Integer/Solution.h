#include <string>
#include <map>
#include <vector>
using namespace std;
/* char alpha[] = { 'I','V','X','L','C','D','M' };
int alpha_num[] = { 1,5,10,50,100,500,1000 };
size_t m_count = sizeof(alpha) / sizeof(char);
size_t n_count = sizeof(alpha_num) / sizeof(int);
vector<char> alphabet(alpha,alpha + m_count);
vector<int> alpha_2_num(alpha_num, alpha_num + n_count); */
map<int,char> alpha_num;
class Solution {
public:
	void ini() {
		alpha_num.insert(pair<int, char>(1,'I'));
		alpha_num.insert(pair<int, char>(5,'V'));
		alpha_num.insert(pair<int, char>(10,'X'));
		alpha_num.insert(pair<int, char>(50,'L'));
		alpha_num.insert(pair<int, char>(100,'C'));
		alpha_num.insert(pair<int, char>(500,'D'));
		alpha_num.insert(pair<int, char>(1000,'M'));
	}
	int romanToInt(string s) {
		ini();
		int sum = 0;
		vector<bool> judge;
		for (int i = 0; i < s.length(); ++i) {
			judge.push_back(false);
		}
		map<int, char>::iterator end_pos;
		for (int i = 0; i < s.length() - 1; ++i) {
			map<int, char>::iterator iter1 = alpha_num.begin();
			map<int, char>::iterator iter2 = alpha_num.begin();
			int fir_pos = 0, sec_pos = 0;
			while (iter1 != alpha_num.end()) {
				if (iter1->second == s[i]) break;
				++iter1;
				++fir_pos;
			}
			while (iter2 != alpha_num.end()) {
				if (iter2->second == s[i + 1]) break;
				++iter2;
				++sec_pos;
			}
			if (i == s.length() - 2) end_pos = iter2;
			if (judge[i] == false && judge[i + 1] == false && fir_pos < sec_pos) {
				judge[i] = true;
				judge[i + 1] = true;
				sum += iter2->first - iter1->first;
			}
			else if (judge[i] == true) {
				continue;
			}
			else
			{
				sum += iter1->first;
			}
		}
		if (judge[s.length() - 1] == false && s.length() != 1) sum += end_pos->first;
		if (s.length() == 1) {
			map<int, char>::iterator iter1 = alpha_num.begin();
			while (iter1 != alpha_num.end()) {
				if (iter1->second == s[0]) {
					sum += iter1->first;
					break;
				}
				iter1++;
			}
		}
		return sum;
	}
};
