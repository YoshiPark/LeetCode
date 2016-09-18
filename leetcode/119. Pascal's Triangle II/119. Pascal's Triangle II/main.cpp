#include <iostream>
#include "Solution.h"
int main() {
	int num;
	while (cin >> num) {
		Solution example;
		vector<int> result = example.getRow(num);
		for (auto i = 0; i < result.size(); ++i) {
			cout << result[i];
			if (i < result.size() - 1) cout << " ";
		}
		cout << endl;
	}
	return 0;
}