#include <iostream>
#include <queue>
#include <string>
#include <unordered_set>
using namespace std;
class Solution {
public:
	int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
		if (beginWord.size() != endWord.size()) return 0; 
		if (beginWord.empty() || endWord.empty()) return 0;  
		int dis = 1;
		int count = 1;
		queue<string> filter;
		filter.push(beginWord);
		wordList.erase(beginWord);
		cout << beginWord << "->";
		while (wordList.size() > 0 && !filter.empty()) {
			string temp = filter.front();
			filter.pop();
			count--;
			for (auto i = 0; i < temp.size(); ++i) {
				string curr = temp;
				for (char j = 'a'; j <= 'z'; ++j) {
					if (curr[i] != j) {
						curr[i] = j;
						if (curr == endWord) {
							cout << curr << endl;
							return dis + 1;
						}
						if (wordList.find(curr) != wordList.end()) {
							filter.push(curr);
							wordList.erase(curr);
							cout << curr << "->";
						}
					}
				}
			}
			if (count == 0) {
				cout << "     ";
				count = filter.size();
				dis++;
			}
		}
		return 0;
	}
};
