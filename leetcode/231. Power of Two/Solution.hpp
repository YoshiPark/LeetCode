class Solution {
public:
    bool isPowerOfTwo(int n) {
        for (int i = 0; i < 32; ++i) {
          if ((n & (1 << i)) == n) return true;
        }
        return false;
    }
};
