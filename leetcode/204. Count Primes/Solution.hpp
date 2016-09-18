class Solution {
public:
    bool is_prime(int n) {
      for (auto i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
      }
      return true;
    }
    int countPrimes(int n) {
        if (n <= 1) return 0;
        else if (n == 2) return 0;
        int m_count = 1;
        for (int i = 3; i <=n; ++n) {
          if (is_prime(i)) m_count++;
        }
        return m_count;
    }
};
