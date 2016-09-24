#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
string basic = "()";
/*class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        for (auto i = 0; i < n; ++i) {
          if (i == 0) {
            result.push_back(basic);
          } else {
            int m_size = result.size();
            for (auto i = 0; i < m_size; ++i) {
              string curr = result[i];
              int len = curr.size();
              for (auto i = 0; i < len; ++i) {
                string ans = curr;
                ans = ans.insert(i,basic);
                auto iter = find(result.begin(),result.end(),ans);
                if (iter == result.end()) {
                  result.push_back(ans);
                }
              }
            }
            for (auto i = 0; i < m_size; ++i) {
              result.erase(result.begin());
            }
          }
        }
        return result;
    }
}; */
class Solution {
private:
    void search(int left, int right, string path, vector<string>& v) {
        cout << path << endl;
        if(!left && !right) { v.push_back(path); return ; }
        if(left > 0) search(left-1, right, path+"(", v);
        if(left < right) search(left, right-1, path+")", v);
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        search(n, n, "", v);
        return v;
    }
};
