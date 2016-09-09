#include <iostream>
#include <iomanip>
using std::cout;
using std::cin;
using std::endl;
int a[1000][1000] = { {0} };
int main() {
	int num;
	do
	{
		cin >> num;
	} while (num % 2 == 0);
	//cin >> num;
	auto pos_x = 0;
	auto pos_y = 0;
	for (auto i = 1; i <= num * num; ++i) {
		if (i == 1) {
			pos_x = 0;
			pos_y = num / 2;
			a[pos_x][pos_y] = i;
		}
		else
		{
			if (pos_x == 0 && pos_y != num - 1) {
				pos_x = num - 1;
				pos_y += 1;
				a[pos_x][pos_y] = i;
			}
			else if (pos_x == 0 && pos_y == num - 1) {
				if (a[num - 1][0] != 0) {
					pos_x += 1;
					a[pos_x][pos_y] = i;
				}
				else
				{
					pos_x = num - 1;
					pos_y = 0;
					a[pos_x][pos_y] = i;
				}
			}
			else if (pos_y == num - 1) {
				pos_x -= 1;
				pos_y = 0;
				a[pos_x][pos_y] = i;
			}
			else if (pos_x - 1 >= 0 && pos_y + 1 < num && a[pos_x-1][pos_y+1] != 0) {
				pos_x += 1;
				a[pos_x][pos_y] = i;
			}
			else
			{
				pos_x -= 1;
				pos_y += 1;
				a[pos_x][pos_y] = i;
			}
		}
	}
	for (auto i = 0; i < num; ++i) {
		for (auto j = 0; j < num; ++j) {
			/* cout << a[i][j];
			if (j != num - 1) cout << " ";
			else cout << endl; */
			cout << std::setiosflags(std::ios::left) << std::setw(5) << a[i][j];
		}
		cout << endl;
	}

	return 0;
}