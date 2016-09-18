#include <string>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) return false;
        if (s.empty() && t.empty()) return true;
        map<char,int> s_map, t_map;
        vector<int> s_pos, t_pos;
        for (size_t i = 0; i < s.length(); ++i) {
          auto iter1 = s_map.find(s[i]);
          auto iter2 = t_map.find(t[i]);
          if (iter1 == s_map.end()) {
            s_pos.push_back(0);
            s_map.insert(pair<char,int>(s[i],i));
          } else {
            s_pos.push_back(iter1->second);
          }
          if (iter2 == t_map.end()) {
            t_pos.push_back(0);
            t_map.insert(pair<char,int>(t[i],i));
          } else {
            t_pos.push_back(iter2->second);
          }
        }
        if (t_map.size() != s_map.size()) return false;
        for (size_t i = 0; i < s_pos.size(); ++i) {
          if (s_pos[i] != t_pos[i]) return false;
        }
        return true;
    }

};
