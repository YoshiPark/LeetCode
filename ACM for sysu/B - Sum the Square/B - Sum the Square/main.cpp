#include <stdio.h>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
using namespace std;
string int_2_string(long long  n) {
	string result;
	stringstream ss;
	ss << n;
	ss >> result;
	return result;
}
int main() {
	long long a, b;
	while (scanf("%lld %lld", &a, &b) != EOF) {
		if (a == 0 && b == 0) break;
		long long a_true = a;
		long long b_true = b;
		int m_count = 0;
		int n_count = 0;
		vector<long long> result1;
		vector<long long> result2;
		result1.push_back(a);
		while (true) {
			vector<long long> number;
			string num_str = int_2_string(a);
			for (size_t i = 0; i < num_str.length(); ++i) {
				long long num = num_str[i] - '0';
				number.push_back(num);
			}
			a = 0;
			for (size_t i = 0; i < number.size(); ++i) {
				a += number[i] * number[i];
			}
			result1.push_back(a);
			if (a == 1) break;
			else if (m_count == 1000) break;
			m_count++;
		}
		result2.push_back(b);
		while (true) {
			vector<long long> number;
			string num_str = int_2_string(b);
			for (size_t i = 0; i < num_str.length(); ++i) {
				long long num = num_str[i] - '0';
				number.push_back(num);
			}
			b = 0;
			for (size_t i = 0; i < number.size(); ++i) {
				b += number[i] * number[i];
			}
			result2.push_back(b);
			if (b == 1) break;
			else if (n_count == 1000) break;
			n_count++;
		}
		bool judge = false;
		vector<int> result;
		for (int i = 0; i < result1.size(); ++i) {
			auto iter = find(result2.begin(), result2.end(),result1[i]);
			if (iter != result2.end()) {
				int dis = distance(result2.begin(), iter);
				result.push_back(i + dis + 2);
			}
		}
		if (result.size() == 0) {
			cout << a_true << " " << b_true << " " << "0\n";
		}
		else
		{
			sort(result.begin(), result.end());
			cout << a_true << " " << b_true << " " << result[0] << endl;
		}
		
		
	}
	return 0;
}