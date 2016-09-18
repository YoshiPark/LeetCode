#include <iostream>
#include <fstream>
#include "Solution.h"
int main() {
	ifstream in("data.txt");
	if (in.fail()) return 0;
	vector<vector<char>> board;
	int row, col;
	in >> row;
	in >> col;
	for (auto i = 0; i < row; ++i) {
		vector<char> temp;
		for (auto j = 0; j < col; ++j) {
			char cmp;
			in >> cmp;
			temp.push_back(cmp);
		}
		board.push_back(temp);
	}
	Solution s;
	s.solve(board);
	for (auto i = 0; i < row; ++i) {
		for (auto j = 0; j < col; ++j) {
			cout << board[i][j];
		}
		cout << endl;
	}
	in.close();
	return 0;
}