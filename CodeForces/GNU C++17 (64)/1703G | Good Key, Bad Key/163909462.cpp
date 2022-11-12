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
            int n;
            long long k; cin >> n >> k;
            vector <long long> a(n); for (auto &x : a) cin >> x;
            vector <vector <long long>> dp(n + 1, vector <long long>(35, 0));
            for (int i = 0; i < 32; ++i) dp[n][i] = 0;
            for (int i = n - 1; i >= 0; --i) {
                  for (int j = 31; j >= 0; --j) {
                        dp[i][j] = max(dp[i + 1][j] + a[i] / (1LL << j) - k, dp[i + 1][j + 1] + a[i] / (1LL << j + 1));
                  }
            }
            cout << *max_element(dp[0].begin(), dp[0].end()) << '\n';
      }
}