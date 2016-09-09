#include <iostream>
#include "Solution.h"
int main() {
	string start;
	string end;
	cin >> start;
	cin >> end;
	unordered_set<string> wordlist;
	int num;
	cin >> num;
	while (num--) {
		string temp;
		cin >> temp;
		wordlist.insert(temp);
	}
	Solution s;
	cout << s.ladderLength(start, end, wordlist) << endl;
	return 0;
}