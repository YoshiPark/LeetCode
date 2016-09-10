#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <fstream>
using namespace std;
bool edge[1005][1005];
int color[1005];
int num[1005];
int min_[1005];
bool judge;
void init() {
	for (int i = 0; i < 1005; ++i) {
		judge = true;
		color[i] = 0;
		num[i] = 0;
		min_[i] = 0;
		for (int j = 0; j < 1005; ++j) {
			edge[i][j] = 0;
		}
	}
}
void get_min(int number) {
	min_[number - 1] = num[number - 1];
	for (int i = number - 2; i >= 0; --i) min_[i] = min(num[i], min_[i + 1]);
}
void link_edge(int number) {
	for (int i = 0; i < number - 1; ++i) {
		for (int j = i + 1; j < number; ++j) {
			if (min_[j] < num[i] && num[i] < num[j]) {
				edge[i][j] = true;
				edge[j][i] = true;
			}
		}
	}
}
void DFS(int pos, int color_, int number) {
	color[pos] = color_;
	for (int i = 0; i < number; ++i) {
		if (edge[pos][i]) {
			if (color[i] == color_) {
				judge = false;
				break;
			}
			else if (color[i] == 0)
			{
				DFS(i, 3 - color_, number);
			}
		}
		if (edge[i][pos]) {
		if (color[i] == color_) {
		judge = false;
		break;
		}
		else if (color[i] == 0)
		{
		DFS(i, 3 - color_, number);
		}
		}
	}
}
string simulate_stack(int number) {
	stack<int> s1;
	stack<int> s2;
	string result;
	if (judge) {
		int pos = 0;
		int pop_number = 1;
		while (pop_number <= number) {
			if (color[pos] == 1) {
				result += "a ";
				s1.push(num[pos]);
				pos++;
			}
			while (!s1.empty() && s1.top() == pop_number) {
				result += "b ";
				s1.pop();
				pop_number++;
			}
			if (color[pos] == 1 && (s1.empty() || s1.top() > num[pos])) {
				continue;
			}
			while (!s2.empty() && s2.top() == pop_number) {
				s2.pop();
				result += "d ";
				pop_number++;
			}
			if (color[pos] == 2) {
				result += "c ";
				s2.push(num[pos++]);
			}
		}
		result = result.substr(0, result.size() - 1);
		cout << result << endl;
	}
	else
	{
		result = "0";
		cout << "0" << endl;
		
	}
	while (!s1.empty()) {
		s1.pop();
	}
	while (!s2.empty()) {
		s2.pop();
	}
	return result;
}
int main() {
	int times;
	ifstream p1("data.txt");
	ofstream p2("answer.txt");
	while (!p1.eof()) {
		string times_str;
		getline(p1, times_str);
		times = atoi(times_str.c_str());
		init();
		string data;
		getline(p1, data);
		for (int i = 0; i < times; ++i) {
			num[i] = data[0] - '0';
			if (i < times - 1) data.erase(0, 2);
		}

		get_min(times);

		link_edge(times);

		for (int i = 0; i < times; ++i) {
			if (!color[i]) DFS(i, 1, times);
		}

		string s = simulate_stack(times);
		p2 << times << endl;
		for (int i = 0; i < times; ++i) {
			p2 << num[i];
			if (i < times) p2 << " ";
		}
		//p2 << endl << s << endl;
		if (s.find('c') == string::npos && s != "0") p2 << "需要1个栈" << endl;
		else if (s.find('c') != string::npos && s != "0") p2 << "需要2个栈" << endl;
		else if (s == "0") p2 << "需要多于两个栈" << endl;
		cout << s << endl;
	}
	p1.close();
	p2.close();
	return 0;
}