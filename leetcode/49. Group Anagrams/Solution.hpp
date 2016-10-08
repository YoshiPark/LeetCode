#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    // vector<vector<string>> groupAnagrams(vector<string>& strs) {
    //     map< map<char,int>, vector<string> > result_map;
    //     int num = strs.size();
    //     for (auto i = 0; i < num; ++i) {
    //       map<char,int> temp;
    //       for (auto j = 0; j < strs[i].length(); ++j) {
    //         auto iter = temp.find(strs[i][j]);
    //         if (iter == temp.end()) {
    //           temp.insert(pair<char,int>(strs[i][j], 1));
    //         } else {
    //           iter->second++;
    //         }
    //       }
    //       bool is_in = false;
    //       for (auto iter = result_map.begin(); iter != result_map.end(); ++iter) {
    //         if (iter->first == temp) {
    //           iter->second.push_back(strs[i]);
    //           is_in = true;
    //           break;
    //         }
    //       }
    //       if (is_in == false) {
    //         vector<string> temp_vec;
    //         temp_vec.push_back(strs[i]);
    //         result_map.insert(pair< map<char,int>, vector<string> >(temp, temp_vec));
    //       }
    //     }
    //     vector<vector<string>> result;
    //     for (auto iter = result_map.begin(); iter != result_map.end(); ++iter) {
    //       result.push_back(iter->second);
    //     }
    //     return result;
    // }
    // vector<vector<string> > groupAnagrams(vector<string>& strs) {
    //   vector<vector<string>> result;
    //   bool a[10000] = {false};
    //   int len = strs.size();
    //   for (auto i = 0; i < len; ++i) {
    //     bool is_in = false;
    //     string prev = strs[i];
    //     if (a[prev.length()] == true) {
    //       sort(strs[i].begin(), strs[i].end());
    //       for (auto it = result.begin(); it != result.end(); ++it) {
    //         if (strs[i] == (*it)[0]) {
    //           (*it).push_back(prev);
    //           is_in = true;
    //           break;
    //         }
    //       }
    //     }
    //     if (is_in == false) {
    //       vector< string > new_vec;
    //       new_vec.push_back(strs[i]);
    //       new_vec.push_back(prev);
    //       result.push_back(new_vec);
    //       a[prev.length()] = true;
    //     }
    //   }
    //   for (auto iter = result.begin(); iter != result.end(); ++iter) {
    //     (*iter).erase((*iter).begin());
    //   }
    //   return result;
    // }
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
      vector<vector<string> > result;
      if (strs.empty()) return result;
      int len = strs.size();
      sort(strs.begin(),strs.end());
      map < string, vector<string> > result_map;
      for (auto i = 0; i < len; ++i) {
        string str = strs[i];
        sort(str.begin(),str.end());
        result_map[str].push_back(strs[i]);
      }
      for (auto iter = result_map.begin(); iter != result_map.end(); ++iter) {
        result.push_back(iter->second);
      }
      return result;
    }
};
