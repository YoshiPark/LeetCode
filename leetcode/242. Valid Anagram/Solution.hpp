#include <map>
#include <string>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> result1;
        map<char, int> result2;
        for (auto i = 0; i < s.length(); ++i) {
          auto iter = result1.find(s[i]);
          if ( iter == result1.end()) {
            result1.insert(pair<char,int> (s[i],1));
          } else {
            iter->second++;
          }
        }
        for (auto i = 0; i < t.length(); ++i) {
          auto iter = result2.find(t[i]);
          if ( iter == result2.end()) {
            result2.insert(pair<char,int> (t[i],1));
          } else {
            iter->second++;
          }
        }
        return result1 == result2;
    }
};
