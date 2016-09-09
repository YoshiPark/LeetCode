#include <string>
using namespace std;
class Solution {
public:
	string convert(string s, int numRows) {
		char ch[1000][1000] = { { '\0' } };
		int row = 0, col = 0;
		bool is_down = true;
		bool is_up = false;
		for (int i = 0; i < s.length(); ++i) {
			if (numRows != 1) {
				if (row != numRows && is_down == true) {
					ch[row][col] = s[i];
					row++;
				}
				else if (row == numRows) {
					col++;
					row -= 2;
					ch[row][col] = s[i];
					is_up = true;
					is_down = false;
					if (row == 0) {
						is_down = true;
						is_up = false;
						row++;
					}
					else
					{
						col++;
						row--;
					}
					
				}
				else if (row != numRows && is_up == true) {
					ch[row][col] = s[i];
					if (row != 0) {
						row--;
						col++;
					}
					else
					{
						is_up = false;
						is_down = true;
						row++;
					}
				}
			}
			else
			{
				ch[row][col] = s[i];
				col++;
			}
			
		}
		string result;
		for (int i = 0; i < numRows; ++i) {
			for (int j = 0; j < col + 1; ++j) {
				if (ch[i][j] != '\0') result += ch[i][j];
			}
		}
		return result;
	}
};