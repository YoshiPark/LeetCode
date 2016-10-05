#include <stdio.h>
#include <algorithm>
using namespace std;
int main() {
  int num, weight;
  scanf("%d%d", &num, &weight);
  int W[1000] = {0};
  int P[1000] = {0};
  int F[1000] = {0};
  int count = 1;
  while (num--) {
      int w, p, c;
      scanf("%d%d%d", &w, &p, &c);
      for (int k = 1; k <= c; k <<= 1) {
        W[count] = k * w;
        P[count++] = k * p;
        c -= k;
      }
      if (c > 0) {
        W[count] = c * w;
        P[count++] = c * p;
      }
  }
  for (int i = 1; i <= count; ++i) {
    for (int j = weight; j >= 0; --j) {
      if (j >= W[i]) {
        F[j] = max(F[j], F[j - W[i]] + P[i]);
      }
    }
  }
  printf("%d\n", F[weight]);
  return 0;
}
