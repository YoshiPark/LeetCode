#include <stdint.h>
class Solution {
public:
    Solution() {
      /*for (uint32_t i = 0; i < 32; ++i) {
        a[i] = 1 << i;
      } */
    }
    int hammingWeight(uint32_t n) {
        int m_count = 0;
        for (uint32_t i = 0; i < 32; ++i) {
          if ((n & (1 << i)) != 0) m_count++;
        }
        return m_count;
    }
  private:
    uint32_t a[32];
};
