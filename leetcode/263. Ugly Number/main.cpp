#include <iostream>
#include "Solution.hpp"
int main(int argc, char const *argv[]) {
    while (true) {
      int num;
      cin >> num;
      Solution example;
      cout << example.isUgly(num) << endl;
    }
    return 0;
}
