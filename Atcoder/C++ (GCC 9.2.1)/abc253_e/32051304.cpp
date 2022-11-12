#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif

using namespace std;

#define ll long long

const int mod = 998244353;
const int N = 1010;
ll dp[N][N * 5], pdp[N][N * 5];
int n, m, k; 

int main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);

      cin >> n >> m >> k;

      if (!k) {
            ll ans = 1;
            for (int i = 0; i < n; ++i) ans = (ans * m) % mod;
            cout << ans << '\n';
            return 0;
      }

      for (int i = 1; i <= m; ++i) dp[n - 1][i] = 1;
      for (int i = 1; i <= m; ++i) pdp[n - 1][i] = (pdp[n - 1][i - 1] + dp[n - 1][i]) % mod;

      for (int i = n - 2; i >= 0; --i) {
            for (int j = 1; j <= m; ++j) {
                  if (j + k <= m) dp[i][j] = (dp[i][j] + pdp[i + 1][m] - pdp[i + 1][j + k - 1] + mod) % mod;
                  if (j - k >= 1) dp[i][j] = (dp[i][j] + pdp[i + 1][j - k] - pdp[i + 1][0] + mod) % mod;
            }
            for (int j = 1; j <= m; ++j) pdp[i][j] = (pdp[i][j - 1] + dp[i][j]) % mod;
      }
      cout << pdp[0][m] << '\n';
}