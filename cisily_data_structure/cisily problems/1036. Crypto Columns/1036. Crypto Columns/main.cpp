#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main() {
	int a[11] = { 0 };
	// ifstream open("test.txt");
	while (true) {
		string keyword;
		//getline(open, keyword);
		getline(cin, keyword);
		if (keyword == "THEEND") {
			break;
			// open.close();
		}
		int count = 0;
		for (char alpha = 'A'; alpha <= 'Z'; ++alpha) {
			for (int size = 0; size < keyword.length(); ++size) {
				if (keyword[size] == alpha) {
					a[count] = size;
					count++;
				}
			}
		}
		string password;
		// getline(open, password);
		getline(cin, password);
		int row_column = password.length() / keyword.length();
		char b[10][10] = { {'\0'} };
		int i = 0;
		int pos = 0;
		while (i < password.length()) {
			int col = a[pos];
			for (int j = 0; j < row_column; ++j) {
				b[j][col] = password[i];
				i++;
			}
			pos++;
		}
		for (int i = 0; i < row_column; ++i) {
			for (int j = 0; j < keyword.length(); ++j) {
				cout << b[i][j];
			}
		}
		cout << endl;
	}
	return 0;
}