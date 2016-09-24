#include <iostream>
#include <stdint.h>
using namespace std;
class Solution {
public:
    int divide(int dividend, int divisor) {
        int result = 0;
        if (dividend == 0) return 0;
        if (divisor == 0) return INT32_MAX;
        if (dividend == INT32_MIN && divisor == -1) return INT32_MAX;
        result = dividend / divisor;
        return result;
    }
};
