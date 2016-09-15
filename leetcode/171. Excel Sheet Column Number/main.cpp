#include <iostream>
#include "Solution.hpp"
int main() {
    string s;
    while (cin >> s) {
        Solution example;
        cout << example.titleToNumber(s) << endl;
    }
    return 0;
}
