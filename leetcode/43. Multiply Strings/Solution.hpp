#include <string>
using namespace std;
class Solution {
public:
    void str_reverse(string& s) {
      int len = s.length();
      for (auto i = 0; i < len / 2; ++i) {
        char temp = s[i];
        s[i] = s[len - 1 - i];
        s[len - 1 - i] = temp;
      }
    }
    string multiply(string num1, string num2) {
        string result;
        if (num1.length() == 0 || num2.length() == 0) return result;
        if (num1 == "0" || num2 == "0") return "0";
        if (num1.length() < num2.length()) {
          string temp = num1;
          num1 = num2;
          num2 = temp;
        }
        str_reverse(num1);
        str_reverse(num2);
        for (auto i = 0; i < num1.length() + num2.length(); ++i) result.push_back('0');
        for (auto i = 0; i < num2.length(); ++i) {
          for (auto j = 0; j < num1.length(); ++j) {
            int mul = (num1[j] - '0') * (num2[i] - '0');
            int carry = mul;
            for (auto k = i+j; k < num1.length() + num2.length(); ++k) {
              int next_carry = 0;
              if (carry <= 0) break;
              auto k_prev = result[k] - '0';
              if (carry >= 10) {
                next_carry += carry / 10;
                carry %= 10;
              }
              auto k_current = carry + k_prev;
              if (k_current >= 10) {
                next_carry += k_current / 10;
                k_current %= 10;
              }
              result[k] = k_current + '0';
              carry = next_carry;
            }
          }
        }
        str_reverse(result);
        if (result[0] == '0') result = result.substr(1, result.length()-1);
        return result;
    }
};
