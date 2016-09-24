#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() == 1) return s;
        string result;
        for (auto i = 0; i < s.length() -1 ; ++i) {
          if (s[i] == s[i+1]) {
            int left = i, right = i+1;
            while (s[left-1] == s[right+1] && left - 1 >= 0 && right + 1 < s.length()) {
              left--;
              right++;
            }
            string temp;
            for (auto k = left; k <= right; ++k) temp += s[k];
            if (temp.length() > result.length()) result = temp;
          }
          if (s[i-1] == s[i + 1] && i - 1 >= 0) {
            int left = i - 1, right = i + 1;
            while (s[left-1] == s[right+1] && left - 1 >= 0 && right + 1 < s.length()) {
              left--;
              right++;
            }
            string temp;
            for (auto k = left; k <= right; ++k) temp += s[k];
            if (temp.length() > result.length()) result = temp;
          }
        }
        return result;
    }
};
