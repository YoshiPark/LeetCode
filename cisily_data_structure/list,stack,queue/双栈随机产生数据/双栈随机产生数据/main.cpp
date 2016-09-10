#include <iostream>
#include <stdlib.h> 
#include <time.h> 
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#define MAX 9
#define RANDOM 20
using namespace std;
string int_2_string(int num) {
	string result;
	stringstream ss;
	ss << num;
	ss >> result;
	return result;
}
int main() {
	srand((unsigned)time(NULL));
	//ofstream f1("data_of_9.txt");

	/* for (auto i = 1; i <= MAX; ++i){
		f1 << i << endl;
		string temp;
		int* a = new int[i];
		for (auto j = 0; j < i; ++j) {
			a[j] = j + 1;
			temp += int_2_string(a[j]);
			if (j < i - 1) temp += " ";
		}
		f1 << temp << endl;
		while (next_permutation(a, a + i)) {
			f1 << i << endl;
			temp.clear();
			for (auto k = 0; k < i; ++k) {
				temp += int_2_string(a[k]);
				if (k < i - 1) temp += " ";
			}
			f1 << temp << endl;
		}
		delete []a;
	} */
	/*ofstream f1("random_data.txt");
	for (auto i = 0; i < RANDOM; ++i) {
		int random_num = 0;
		while (random_num < 5) {
			random_num = rand() % 10;
		}
		string temp;
		int* a = new int[random_num];
		int all_sort = 1;
		for (auto k = 1; k <= random_num; ++k) all_sort *= k;
		for (auto j = 0; j < random_num; ++j) a[j] = j + 1;
		int random_sort = 0;
		while (random_sort < 20) {
			random_sort = rand() % all_sort;
		}
		int m_count = 1;
		while (next_permutation(a, a + random_num)) {
			if (m_count == random_sort) {
				f1 << random_num << endl;
				temp.clear();
				for (auto k = 0; k < random_num; ++k) {
					temp += int_2_string(a[k]);
					if (k < random_num - 1) temp += " ";
				}
				f1 << temp << endl;
				break;
			}
			else
			{
				m_count++;
			}
		}
		delete[]a;
	} */
	ofstream f1("sort_data.txt");
	for (auto i = 1; i <= MAX; ++i){
	//f1 << i << endl;
	string temp;
	int* a = new int[i];
	for (auto j = 0; j < i; ++j) {
	a[j] = j + 1;
	temp += int_2_string(a[j]);
	//if (j < i - 1) temp += " ";
	}
	f1 << temp << endl;
	while (next_permutation(a, a + i)) {
	//f1 << i << endl;
	temp.clear();
	for (auto k = 0; k < i; ++k) {
	temp += int_2_string(a[k]);
	//if (k < i - 1) temp += " ";
	}
	f1 << temp << endl;
	}
	delete []a;
	} 
	cout << "Succeed!\n";
	f1.close();
	return 0;
}