#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
using namespace std;
 
const int N = 505;
int64_t dp[N][N], a[N], d[N];
int n, l, k;
 
int64_t rec(int i, int j) {
      if (j > k) return 1e18;
      if (i == n) return 0;
      int64_t &ret = dp[i][j];
      if (~ret) return dp[i][j];
      
      ret = (d[i + 1] - d[i]) * a[i] + rec(i + 1, j);
      for (int kk = i + 1; kk < n; ++kk) {
            ret = min(ret, (d[kk + 1] - d[i]) * a[i] + rec(kk + 1, j + kk - i));
      }
 
      return ret;
}
 
int main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
 
      cin >> n >> l >> k;
      for (int i = 0; i < n; ++i) cin >> d[i];
      for (int i = 0; i < n; ++i) cin >> a[i];
      d[n] = l;
 
      memset(dp, -1, sizeof dp);
      cout << rec(0, 0) << '\n';
}