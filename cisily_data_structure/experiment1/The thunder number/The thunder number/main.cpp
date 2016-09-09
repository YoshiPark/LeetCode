#include <iostream>
#include <stdio.h>
#include <string>
#include<sstream>
#include<time.h>
using std::string;
string int_2_string(int num) {
	string temp;
	std::stringstream ss;
	ss << num;
	ss >> temp;
	return temp;
}
void break_2_num(int & num1, int & num2, string num_str, int pos) {
	string num1_str = num_str.substr(0, pos);
	string num2_str = num_str.substr(pos, num_str.length() - pos);
	num1 = atoi(num1_str.c_str());
	num2 = atoi(num2_str.c_str());
}
int main() {
	//time_t start = clock();
	int number = 0;
	int num1 = 0;
	int num2 = 0;
	for (auto i = 0; i < 10000; ++i) {
		number = i * i;
		string num_str = int_2_string(number);
		for (auto j = 1; j < num_str.length(); ++j) {
			break_2_num(num1, num2, num_str, j);
			if (num1 > number || num2 > number) {
				break;
			}
			if (num1 + num2 == i) { std::cout << i*i << std::endl; }
		}
	}
	//time_t end = clock();

	return 0;
}