#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int a[1000][1000] = { {0} };
bool wrong = false;
int main() {
	int num;
	cin >> num;
	for (auto i = 0; i < num; ++i) {
		for (auto j = 0; j < num; ++j) {
			cin >> a[i][j];
		}
	}
	auto amount = 0;
	for (auto i = 0; i < num; ++i) {
		amount += a[0][i];
	}
	for (auto i = 0; i < num; ++i) {
		auto row_number = 0;
		for (auto j = 0; j < num; ++j) {
			row_number += a[i][j];
		}
		if (row_number != amount) {
			wrong = true;
			break;
		}
	}
	if (wrong == false) {
		for (auto i = 0; i < num; ++i) {
			auto col_number = 0;
			for (auto j = 0; j < num; ++j) {
				col_number += a[j][i];
			}
			if (col_number != amount) {
				wrong = true;
				break;
			}
		}
	}
	if (wrong == false) {
		auto diagonal_number = 0;
		for (auto i = 0; i < num; ++i) {
			diagonal_number += a[i][i];
		}
		if (diagonal_number != amount) {
			wrong = true;
		}
	}
	if (wrong == true) cout << "No!\n";
	else cout << "Yes!\n";
	return 0;
}