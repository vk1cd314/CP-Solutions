#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
using namespace std;
 
const int N = 1e3 + 10;
int dp[N], b[N], c[N];
int n, k;
 
int main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
 
      memset(dp, 0x3f3f3f, sizeof dp);
      dp[1] = 0;
      for (int i = 1; i < N; ++i) {
            for (int x = 1; x <= i; ++x) {
                  if (i + i / x >= N) continue;
                  dp[i + i / x] = min(dp[i + i / x], dp[i] + 1);
            }
      }
 
      // for (int i = 1; i <= 20; ++i) cout << dp[i] << ' ';
      // cout << '\n';
 
      // cout << *max_element(dp + 1, dp + N) << '\n'; // 12
 
      int t; cin >> t;
      while (t--) {
            cin >> n >> k;
            for (int i = 0; i < n; ++i) cin >> b[i], b[i] = dp[b[i]];
            for (int i = 0; i < n; ++i) cin >> c[i];
            if (k >= n * 12) {
                  cout << accumulate(c, c + n, 0) << '\n';
            } else {
                  int dp1[k + 1];
                  memset(dp1, 0, sizeof dp1);
                  for (int i = 0; i < n; ++i) {
                        for (int j = k; j >= 0; j--) {
                              if (b[i] <= j) {
                                    dp1[j] = max(dp1[j], dp1[j - b[i]] + c[i]);
                              }
                        }
                  }
                  cout << *max_element(dp1, dp1 + k + 1) << '\n';
            }
      }
}