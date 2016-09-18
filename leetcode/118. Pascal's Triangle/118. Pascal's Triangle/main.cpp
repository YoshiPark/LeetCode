#include <iostream>
#include "Solution.h"
int main() {
	int num;
	while (cin >> num) {
		Solution example;
		vector<vector<int>> result = example.generate(num);
		for (auto i = 0; i < result.size(); ++i) {
			for (auto j = 0; j < i + 1; ++j) {
				cout << result[i][j];
				if (j < i) cout << " ";
			}
			cout << endl;
		}
	}
	
	return 0;
}