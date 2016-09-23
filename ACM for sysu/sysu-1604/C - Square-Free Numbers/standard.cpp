#include <algorithm>
#include <stdio.h>
#include <fstream>
using namespace std;
int tot, n;

int main() {
  ofstream p1("standard.txt");
  tot = 999999;
  n = 2;
  while (tot--) {
    int temp = n;
    int ans = 1;
    for (int i = 2; i * i <= n; ++i) {
      int tt = 0;
      if (n % i == 0) {
        while (n % i == 0) {
          tt++;
          n /=i;
        }
      }
      ans = max(ans,tt);
    }
    p1 << temp << ":" << ans << endl;
    n = temp + 1;
  }
  p1.close();
  return 0;
}
