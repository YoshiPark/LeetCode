#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
int ABS (int x) {
  if (x < 0) return -x;
  else return x;
}
int a[105], cnt[105];
bool f[105][105][105];
int main() {
    int cas,i,j,k,t1,ans,n,sum;
    for (scanf("%d", &cas); cas; --cas) {
      for (i = 1; i <= 9; ++i) scanf("%d", &cnt[i]);
      n = 0;
      for (i = 1; i <= 9; ++i) {
        for (j = 1; j <= cnt[i]; ++j) a[++n] = i;
      }
      sum = 0;
      for (i = 1; i <= 9; ++i) sum += cnt[i] * i;
      memset(f,0,sizeof(f));
      f[0][0][0] = 1;
      for (i = 1; i <= n; ++i) {
        for (j = 0; j <= i; ++j) {
          for (k = 0; k <= sum; ++k) {
            f[i][j][k] = f[i-1][j][k];
            if (k >= a[i] && j) f[i][j][k] = f[i-1][j-1][k - a[i]];
          }
        }
      }
      ans = 1000000;
      for (i = 0; i <= n; ++i) {
        for (j = 0; j <= sum; ++j) {
          if (f[n][i][j]) {
            t1 = ABS(j-(sum-j));
            if (t1 % 11 == 0) {
              if (n-i == i) ans = min(ans, 0); else
              if (i > n-i) ans = min(ans, i-n+i-1); else
              if (i < n-i) ans = min(ans, n-i-i);
            }
          }
        }
      }
      if (ans == 1000000) puts("-1");
      else printf("%d\n", ans+n);
    }
    return 0;
}
