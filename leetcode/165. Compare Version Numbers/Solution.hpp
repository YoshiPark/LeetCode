#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> get_everypart(string num_str) {
      std::vector<int> number;
      if (num_str.empty()) return number;
      while (!num_str.empty()) {
        auto divide_symbol = num_str.find('.');
        if (divide_symbol == string::npos) {
          int num = atoi(num_str.c_str());
          number.push_back(num);
          break;
        }
        string part = num_str.substr(0, divide_symbol);
        int num = atoi(part.c_str());
        number.push_back(num);
        num_str.erase(0, divide_symbol+1);
      }
      return number;
    }
    int compareVersion(string version1, string version2) {
        int result = 0;
        auto version1_vec = get_everypart(version1);
        auto version2_vec = get_everypart(version2);
        int sub = version1_vec.size() > version2_vec.size()?version1_vec.size() - version2_vec.size():version2_vec.size() - version1_vec.size();
        for (auto i = 0; i < sub; ++i) {
          if (version1_vec.size() > version2_vec.size()) version2_vec.push_back(0);
          else version1_vec.push_back(0);
        }
        for (size_t i = 0; i < version1_vec.size(); ++i) {
          if (version1_vec[i] > version2_vec[i]) return 1;
          else if (version1_vec[i] < version2_vec[i]) return -1;
          else continue;
        }
        return result;
    }
};
