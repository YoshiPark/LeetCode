#include <iostream>
#include "Solution.hpp"
int main() {
    int number;
    while (cin >> number) {
      Solution example;
      cout << example.trailingZeroes(number) << endl;
    }
    return 0;
}
