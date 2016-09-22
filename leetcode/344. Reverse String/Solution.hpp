#include <string>
using namespace std;
class Solution {
public:
    string reverseString(string s) {
        string result;
        int m_size = s.length();
        for (auto i = 0; i < m_size; ++i) {
          char temp = s[m_size - 1 - i];
          result.push_back(temp);
        }
        return result;
    }
};
