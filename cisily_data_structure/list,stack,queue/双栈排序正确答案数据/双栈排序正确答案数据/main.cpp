#include <iostream>  
#include <cstdio>  
#include <cstdlib>  
#include <string>  
#include <algorithm>  
#include <fstream>
#include <stack>  
using namespace std;
const int maxn = 1000 + 5;
bool Edge[maxn][maxn];
int s[maxn], F[maxn], color[maxn];
stack<int> staA, staB;
int n;
bool flag;
void  NoAnswer()
{
	flag = false;
	printf("0\n");
	return;
}
void  dfs(int x, int c)
{
	color[x] = c;
	for (int i = 1; i <= n; ++i)
		if (Edge[x][i])
		{
			if (color[i] == c) NoAnswer();
			if (!color[i])
				dfs(i, 3 - c);
			if (flag == false) break;
		}
}
int main() {
	ifstream f1("data_of_5.txt");
	ofstream f2("result_of_5.txt");
	while (!f1.eof()) {
		while (!staA.empty()) staA.pop();
		while (!staA.empty()) staB.pop();
		for (int i = 0; i < maxn; ++i) {
			s[i] = F[i] = color[i] = 0;
			for (int j = 0; j < maxn; ++j) {
				Edge[i][j] = Edge[j][i] = false;
			}
		}
		flag = true;
		string n_str;
		getline(f1, n_str);
		n = atoi(n_str.c_str());
		string data;
		getline(f1, data);
		for (int i = 1; i <= n; ++i) {
			s[i] = data[0] - '0';
			if (i < n) data.erase(0, 2);

		}
		F[n + 1] = 0x7fffffff;
		for (int i = n; i >= 1; --i) F[i] = min(s[i], F[i + 1]);


		for (int i = 1; i < n; ++i)
			for (int j = i + 1; j <= n; ++j)
				if (s[i] < s[j] && F[j + 1] < s[i])
					Edge[i][j] = Edge[j][i] = true;

		for (int i = 1; i <= n; ++i)
			if (!color[i]) dfs(i, 1);

		string result;
		if (flag == true) {
			int aim = 1;
			for (int i = 1; i <= n; ++i)
			{
				if (color[i] == 1)
				{
					staA.push(s[i]);
					result += "a ";
				}
				else
				{
					staB.push(s[i]);
					result += "c ";
				}

				while (!staA.empty() && staA.top() == aim ||
					!staB.empty() && staB.top() == aim)
				{
					if (!staA.empty() && staA.top() == aim)
					{
						staA.pop();
						result += "b ";
					}
					else
					{
						staB.pop();
						result += "d ";
					}
					aim++;
				}
			}
		}
		else
		{
			result = "0";
		}
		f2 << n << endl;
		for (int i = 1; i <= n; ++i) {
			f2 << s[i];
			if (i < n) f2 << " ";
		}
		f2 << endl << result << endl;
		cout << result << endl;
	}
	cout << "Succeed!\n";
	f1.close();
	f2.close();
	return 0;
}
