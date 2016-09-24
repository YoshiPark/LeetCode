#include <string>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    Solution() {
        for (auto i = 0; i < 10; ++i) {
          if (i == 0 || i == 1) num_alpha.push_back(0);
          else if (i == 7 || i == 9) num_alpha.push_back(4);
          else num_alpha.push_back(3);
        }
        char alpha = 'a';
        for (auto i = 2; i < 10; ++i) {
          int times = 0;
          vector<char> temp;
          while (times < num_alpha[i]) {
            temp.push_back(alpha);
            times++;
            alpha++;
          }
          digit_alpha.insert(pair<int, vector<char>> (i, temp));
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        int total = 1;
        int len = digits.length();
        for (auto i = 0; i < len; ++i) total *= num_alpha[digits[i] - '0'];
        if (total == 0) return result;
        int repeat = total;
        int temp = 1;
        for (auto i = 0; i < len; ++i) {
          if (i == 0) {
            repeat = repeat / num_alpha[digits[i] - '0'];
            auto iter = digit_alpha.find(digits[i] - '0');
            for (auto j = 0; j < iter->second.size(); ++j) {
              for (auto k = 0; k < repeat; ++k) {
                string temp;
                temp += iter->second[j];
                result.push_back(temp);
              }
            }
          } else {
            temp *= num_alpha[digits[i - 1] - '0'];
            repeat = repeat / num_alpha[digits[i] - '0'];
            auto iter = digit_alpha.find(digits[i] - '0');
            int pos = 0;
            for (auto l = 0; l < temp; ++l) {
              for (auto j = 0; j < iter->second.size(); ++j) {
                for (auto k = 0; k < repeat; ++k) {
                  result[pos++] += iter->second[j];
                }
              }
            }
          }
        }
        return result;
    }
private:
    vector<int> num_alpha;
    map<int, vector<char> > digit_alpha;
};
