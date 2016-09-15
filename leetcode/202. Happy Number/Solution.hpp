#include <string>
#include <sstream>
#include <vector>
using namespace std;
class Solution {
public:
    string int_2_string(int n) {
      string result;
      stringstream ss;
      ss << n;
      ss >> result;
      return result;
    }
    bool isHappy(int n) {
      int m_count = 0;
        while (true) {
            vector<int> number;
            string num_str = int_2_string(n);
            for (size_t i = 0; i < num_str.length(); ++i) {
                int num = num_str[i] - '0';
                number.push_back(num);
            }
            n = 0;
            for (size_t i = 0; i < number.size(); ++i) {
              n += number[i] * number[i];
            }
            if (n == 1) return true;
            else if (m_count == 100) return false;
            m_count++;
        }
        return false;
    }
};
