#include <iostream>
#include <map>
using namespace std;
int main() {
	int num;
	while (cin >> num) {
		map<int, int> data;
		for (int i = 0; i < num; ++i) {
			int number;
			cin >> number;
			map<int, int>::iterator iter = data.find(number);
			if (iter != data.end()) {
				iter->second++;
			}
			else
			{
				data.insert(pair<int, int>(number, 1));
				
			}
		}
		for (map<int, int>::iterator iter = data.begin(); iter != data.end(); ++iter) {
			if (iter->second % 2 != 0) {
				cout << iter->first << endl;
				break;
			}
		}
	}
}