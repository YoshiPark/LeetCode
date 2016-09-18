#include <string>
#include <map>
#include <vector>
#include <set>
using namespace std;
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        map<char, vector<int> > result;
        for (size_t i = 0; i < pattern.length(); ++i) {
          auto iter = result.find(pattern[i]);
          if (iter == result.end()) {
            vector<int> temp;
            temp.push_back(i);
            result.insert(pair<char, vector<int> >(pattern[i],temp));
          } else {
            iter->second.push_back(i);
          }
        }
        vector<string> str_vec;
        while (!str.empty()) {
          auto pos = str.find(' ');
          if (pos == string::npos) {
            str_vec.push_back(str);
            break;
          } else {
            string part = str.substr(0, pos);
            str_vec.push_back(part);
            str.erase(0, pos+1);
          }
        }
        if (str_vec.size() != pattern.length()) return false;
        set<string> same;
        for (auto iter = result.begin(); iter != result.end(); ++iter) {
          auto sub_str = str_vec[iter->second[0]];
          same.insert(sub_str);
          for (auto it = iter->second.begin(); it != iter->second.end(); ++it) {
            if (sub_str != str_vec[*it]) return false;
          }
        }
        if (same.size() != result.size()) return false;
        return true;
    }
};
