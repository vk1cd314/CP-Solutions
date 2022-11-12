#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif

using namespace std;

int main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);

      int t; cin >> t;
      while (t--) {
            long long n, x; cin >> n >> x;
            vector <vector <long long>> dp(34, vector <long long>(2));
            dp[0][0] = dp[0][1] = 1;
            for (int i = 1; i < 34; ++i) {
                  for (int j = 0; j < 2; ++j) {
                        if (x & 1ll << (i - 1)) {
                              dp[i][j] = dp[i - 1][j];
                        } else {
                              if (n & 1ll << (i - 1)) {
                                    dp[i][j] = dp[i - 1][j] + dp[i - 1][0];
                              } else {
                                    if (!j) dp[i][j] = 2ll * dp[i - 1][j];
                                    else dp[i][j] = dp[i - 1][j];
                              }
                        }
                  }
            }
            cout << dp[33][1] - 1 << '\n';
      }
}
// (n ^ k) & x == 0
// no common bits
// k subset of ~x ^ n