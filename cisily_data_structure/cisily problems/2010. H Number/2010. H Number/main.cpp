#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

bool is_Hnumber(int number) {
	char num_str[10];
	sprintf(num_str, "%d", number);
	for (int i = 1; i < strlen(num_str) - 1; ++i) {
		int mid = num_str[i] - '0';
		int prev = num_str[i - 1] - '0';
		int next = num_str[i + 1] - '0';
		if (mid != prev + next && mid != prev - next && mid != next - prev) return false;
	}
	return true;
}
int main() {
	int num;
	cin >> num;
	int count = 0;
	if (num <= 100) {
		if (num < 100)cout << num << endl;
		if (num == 100) cout << num - 1 << endl;
	}
	else
	{
		for (int i = 101; i <= num; ++i) {
			if (is_Hnumber(i)) count++;
		}
		count += 99;
		cout << count << endl;
	}
	return 0;
}