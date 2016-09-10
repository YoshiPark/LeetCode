#include <vector>
#include <set>
using namespace std;
class Solution {
public:
	bool calculate_matrix(int x_start, int x_end, int y_start, int y_end, vector<vector<char>>& board) {
		set<int> data;
		auto dot_count = 0;
		for (int i = x_start; i < x_end; ++i) {
			for (int j = y_start; j < y_end; ++j) {
				if (board[i][j] != '.') {
					data.insert(board[i][j]);
				}
				else
				{
					dot_count++;
				}
			}
		}
		if (data.size() != 9 - dot_count) return false;
		return true;
	}
	bool isValidSudoku(vector<vector<char>>& board) {
		if (board.empty() || board.size() != 9) return false;;
		for (auto i = 0; i < board.size(); ++i) {
			if (board[i].size() != 9) return false;
		}
		set<int> data1,data2;
		for (auto i = 0; i < board.size(); ++i) {
			int row_dot_count = 0;
			int col_dot_count = 0;
			for (auto j = 0; j < board[i].size(); ++j) {
				if (board[i][j] != '.' && board[j][i] != '.') {
					data1.insert(board[i][j]);
					data2.insert(board[j][i]);
				}
				else if(board[i][j] != '.' && board[j][i] == '.') {
					data1.insert(board[i][j]);
					col_dot_count++;
				}
				else if (board[i][j] == '.' && board[j][i] != '.'){
					row_dot_count++;
					data2.insert(board[j][i]);
				}
				else
				{
					row_dot_count++;
					col_dot_count++;
				}
			}
			if (data1.size() != 9 - row_dot_count || data2.size() != 9 - col_dot_count) return false;
			data1.clear();
			data2.clear();
		}
		bool judge = true;
		for (int i = 0; i < board.size(); i += 3) {
			for (int j = 0; j < board.size(); j += 3) {
				judge = calculate_matrix(i, i + 3, j, j + 3, board);
				if (!judge) return false;
			}
		}
		return true;
	}
};
