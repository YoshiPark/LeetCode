#include <iostream>
#include <fstream>
#include <string>
#include "Solution.h"
#define COL_ROW 9
int main() {
	ifstream p1("data.txt");
	vector<vector<char>> board;
	for (auto i = 0; i < COL_ROW; ++i) {
		vector<char> temp;
		string char_str;
		getline(p1, char_str);
		for (auto j = 0; j < char_str.length(); ++j) {
			temp.push_back(char_str[j]);
		}
		board.push_back(temp);
	}
	Solution example;
	cout << example.isValidSudoku(board) << endl;
	return 0;
}