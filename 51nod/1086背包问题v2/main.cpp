#include <stdio.h>
#include <algorithm>
using namespace std;
int main() {
   int num, weight;
   scanf("%d%d", &num, &weight);
   int F[101] = {0};
   int W[101] = {0};
   int P[101] = {0};
   int C[101] = {0};
   for (auto i = 0; i < num; ++i) {
     scanf("%d%d%d", &W[i+1], &P[i+1], &C[i+1]);
   }
   int w1, p1;
   for (int i = 1; i <= num; ++i) {
     int j;
     for (j = 1; j <= C[i]; j <<= 1) {
       w1 = j * W[i];
       p1 = j * P[i];
       for (int v = weight; v >= w1; --v) {
         F[v] = max(F[v], F[v - w1] + p1);
       }
       C[i] -= j;
     }
     j = C[i];
     w1 = j * W[i];
     p1 = j * P[i];
     for (int v = weight; v >= w1; --v) {
       F[v] = max(F[v], F[v - w1] + p1);
     }

    //  for (int i = 1; i <= weight; ++i) {
    //    printf("%d ", F[i]);
     //
    //  }
    //  printf("\n");
   }
   printf("%d\n", F[weight]);
   return 0;
}
