#include <string>
#include <cmath>
using namespace std;
class Solution {
public:
    int titleToNumber(string s) {
        int number = 0;
        for (int i = s.length()-1; i >= 0; --i) {
          int num = s[i] - 'A' + 1;
          num *= pow(26, s.length()-1-i);
          number += num;
        }
        return number;
    }
};
