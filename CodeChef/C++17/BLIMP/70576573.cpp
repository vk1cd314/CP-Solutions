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
            int n; cin >> n;
            long long x, y; cin >> x >> y;
            vector <long long> a(n); for (auto &x : a) cin >> x;
            if (n == 1) {
                  cout << min((a[0] + x - 1) / x, (a[0] + y - 1) / y) << '\n';
                  continue;
            }
            if (x <= y) {
                  long long mx = *max_element(a.begin(), a.end());
                  cout << (mx + y - 1) / y << '\n';
            } else {
                  long long mx = *max_element(a.begin(), a.end());
                  long long ans = (mx + y - 1) / y;
                  vector <long long> dp(n + 1);
                  dp[n] = 0;
                  for (int i = n - 1; i >= 0; --i) {
                        long long yops = (a[i] + y - 1) / y;
                        dp[i] = dp[i + 1];
                        if (yops > dp[i + 1]) {
                              long long have = yops - dp[i + 1];
                              long long rem = a[i] - y * dp[i + 1];
                              long long xops = (rem + x - 1) / x;
                              long long ext = (a[i] - x * xops + y - 1) / y;
                              dp[i] = max(dp[i + 1], min(xops, have) + max(dp[i + 1], ext));
                        }
                  }
                  cout << min(ans, dp[0]) << '\n';
            }
      }
}