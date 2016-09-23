#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
bool is_11(string s) {
    int add = 0, sub = 0;
    while (!s.empty()) {
      if (s[0] == '+') {
        add += s[1] - '0';
      } else {
        sub += s[1] - '0';
      }
      s.erase(0,2);
    }
    int result = abs(add - sub);
    // cout << result << endl;
    return (result % 11 == 0);
}
string generator(int total, int n) {
    string result;
    int k = 0, a = 1;
    while (true) {
      if (total <= pow(2,k)) break;
      k++;
    }
    for (auto i = 0; i < k; ++i) result.push_back('-');
    for(auto i = 0; i < k; ++i) {
      if( n & a) result[i] = '+';
      a<<=1;
    }
    return result;
}
int main(int argc, char const *argv[]) {
    int num;
    cin >> num;
    while (num--) {
      int true_size = -1;
      string number;
      int a[9] = {0};
      for (auto i = 0; i < 9; ++i) {
        cin >> a[i];
        for (auto j = 0; j < a[i]; ++j) number.push_back('0' + i + 1);
      }
      int total = int(pow(2,number.size()));
      for (auto i = 0; i < total; ++i) {
        string symbol = generator(total,i);
        int m_count = 0;
        int len = symbol.size();
        for (auto i = 0; i < len; ++i) {
          if (symbol[i] == '+') m_count++;
        }
        int n_count = len - m_count;
        string result;
        for (auto i = 0; i < number.size(); ++i) {
          result += symbol[i];
          result += number[i];
        }
        // cout << result << endl;
        if (is_11(result)) {
          if (abs(m_count - n_count) <= 1) {
            true_size = number.size();
          } else {
            true_size = number.size() + abs(m_count - n_count) - 1;
          }
          break;
        }
      }
      cout << true_size << endl;
    }
    return 0;
}
