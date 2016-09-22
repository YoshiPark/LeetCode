#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string reverseVowels(string s) {
        vector<int> pos;
        string result = s;
        int len = s.length();
        for (auto i = 0; i < len; ++i) {
          if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') pos.push_back(i);
          else if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') pos.push_back(i);
        }
        int size = pos.size();
        for (auto i = 0; i < size / 2; ++i) {
            char temp = result[pos[i]];
            result[pos[i]] = result[pos[size-1-i]];
            result[pos[size-1-i]] = temp;
        }
        return result;
    }
};
