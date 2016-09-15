#include <iostream>
#include "Solution.hpp"
int main() {
    int number;
    while (cin >> number) {
      Solution example;
      cout << example.isHappy(number) << endl;
    }
    return 0;
}
