#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
	void solve(vector<vector<char>>& board) {
		queue< pair<int, int> > pos;
		int row = board.size();
		if (board.size() == 0) return;
		int col = board[0].size();
		if (col == 0) return;
		for (auto i = 0; i < row; ++i) {
			if (board[i][0] == 'O') pos.push(pair<int, int>(i, 0));
			if (board[i][col - 1] == 'O') pos.push(pair<int, int>(i, col - 1));
		}
		for (auto j = 1; j < col - 1; ++j) {
			if (board[0][j] == 'O') pos.push(pair<int, int>(0, j));
			if (board[row - 1][j] == 'O') pos.push(pair<int, int>(row - 1, j));
		}
		while (!pos.empty()) {
			auto node = pos.front();
			int pos_x = node.first, pos_y = node.second;
			board[pos_x][pos_y] = '$';
			pos.pop();
			if (pos_x > 0 && board[pos_x - 1][pos_y] == 'O') pos.push(pair<int, int>(pos_x - 1, pos_y));
			if (pos_x < row - 1 && board[pos_x + 1][pos_y] == 'O') pos.push(pair<int, int>(pos_x + 1, pos_y));
			if (pos_y > 0 && board[pos_x][pos_y - 1] == 'O') pos.push(pair<int, int>(pos_x, pos_y - 1));
			if (pos_y < col - 1 && board[pos_x][pos_y + 1] == 'O')  pos.push(pair<int, int>(pos_x, pos_y + 1));
		}
		for (auto i = 0; i < row; ++i) {
			for (auto j = 0; j < col; ++j) {
				cout << board[i][j];
			}
			cout << endl;
		}
		for (auto i = 0; i < row; ++i) {
			for (auto j = 0; j < col; ++j) {
				if (board[i][j] == 'O') board[i][j] = 'X';
				if (board[i][j] == '$') board[i][j] = 'O';
			}
		}
	}
};
