#include <iostream>
using namespace std;
int main() {
    int num;
    cin >> num;
    while (num--) {
      long long int col, short_col, diffence;
      cin >> col;
      cin >> short_col;
      cin >> diffence;
      long long int sum = 0;
      for (long long int i = 0; i < col; ++i) {
        sum += short_col + diffence * i;
      }
      cout << sum << endl;
    }
    return 0;
}
