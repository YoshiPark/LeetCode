#include <vector>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int m_count = 0;
        auto iter = nums.begin();
        while (iter != nums.end()) {
            if (*iter == 0) {
              iter = nums.erase(iter);
              m_count++;
            }  else {
              iter++;
            }
        }
        for (auto i = 0; i < m_count; ++i) {
          nums.push_back(0);
        }
    }
};
