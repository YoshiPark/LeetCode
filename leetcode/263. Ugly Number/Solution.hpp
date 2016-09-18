#include <set>
using namespace std;
class Solution {
public:
    bool is_prime(int number) {
      for (auto i = 2; i * i <=number; ++i) {
       if (number % i == 0) return false;
     }
     return true;
    }
    bool isUgly(int num) {
        if (num <= 0) return false;
        if (num == 1 || num == 2 || num == 3 || num == 5) return true;
        while (num != 1) {
          if (num % 2 == 0) num /= 2;
          else if (num % 3 == 0) num /= 3;
          else if (num % 5 == 0) num /= 5;
          else {
            return true;
          }
        }
        return false;
    }
};
