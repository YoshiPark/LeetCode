#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define  N 11
#define M 220

using namespace std;
int tot, d[N], sum[N], f[2][M][N];

int trans(int x) {
  x %= 11;
  x += 11;
  x %= 11;
  return x;
}

int main(int argc, char const *argv[]) {
  scanf("%d", &tot);
  while (tot--) {
    sum[0] = 0;
    for (int i = 1; i <= 9; i++) {
      scanf("%d", &d[i]);
      sum[i] = sum[i-1] + d[i];
    }
    if (sum[9] == 0) {
      puts("1");
      continue;
    }
    memset(f,0, sizeof(f));
    int s = 0;
    f[0][0][0] = 1;
    for (int i = 1; i <= 9; i++) {
      s ^= 1;
      for (int j = 0; j <= sum[i]; j++) {
        for (int k = 0; k < N; k++) {
          f[s][j][k] = 0;
        }
      }
      for (int j = 0; j <= sum[i-1]; j++) {
        for (int k = 0; k < N; k++) {
          if (f[s^1][j][k]) {
            for (int l = 0; l <= d[i]; l++) {
              f[s][j+1][trans(k+i*(l-(d[i]-l)))] = 1;
            }
          }
        }
      }
    }
    int ans = 0x7f7f7f7f;
    for (int i = 0; i <= sum[9]; i++) {
        if (f[s][i][0]) {
          int j1 = i;
          int j2 = sum[9] - i;
          if (j1 < j2) swap(j1,j2);
          if (j1 == j2) j1 = j1 * 2;
          else j1 = j1 * 2 - 1;
          ans = min(ans,j1);
        }
    }
    if (ans == 0x7f7f7f7f) puts("-1");
    else printf("%d\n", ans);
  }
  return 0;
}
