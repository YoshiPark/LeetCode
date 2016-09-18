#include <stdint.h>
class Solution {
public:
    Solution() {
        for (uint32_t i = 0; i < 32; ++i) {
          a[i] = 1 << (31 - i);
        }
    }
    uint32_t reverseBits(uint32_t n) {
          uint32_t result = 0;
          for (uint32_t i = 0; i < 32; ++i) {
            if ((n & (1 << i)) != 0) result += a[i];
          }
          return result;
    }
private:
    uint32_t a[32];
};
