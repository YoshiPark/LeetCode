#include <vector>
#include <string>
#include <sstream>
using namespace std;
class Solution {
public:
    string int_2_string(int num) {
      string result;
      stringstream ss;
      ss << num;
      ss >> result;
      return result;
    }
    int addDigits(int num) {
        while (num >= 10) {
          string num_str = int_2_string(num);
          vector<int> per_digit;
          for (auto i = 0; i < num_str.size(); ++i) {
            int number = num_str[i] - '0';
            per_digit.push_back(number);
          }
          num = 0;
          for (auto i = 0; i < per_digit.size(); ++i) {
            num += per_digit[i];
          }
        }
        return num;
    }
};
