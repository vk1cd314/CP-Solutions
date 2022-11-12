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
            long long x; cin >> n >> x;
            vector <long long> a(n);
            for (auto &f : a) cin >> f;
            // if (n == 1) {
            //       cout << "0\n";
            //       continue;
            // }
            vector <vector <long long>> dp(n, vector <long long>(2, 0));
            for (int i = 1; i < n; ++i) {
                  dp[i][0] = max(dp[i - 1][0] + (a[i - 1] ^ a[i]), dp[i - 1][1] + ((a[i - 1] + x) ^ a[i]));
                  dp[i][1] = max(dp[i - 1][1] + ((a[i - 1] + x) ^ (a[i] + x)), dp[i - 1][0] + (a[i - 1] ^ (a[i] + x)));
            }
            cout << max(dp[n - 1][0], dp[n - 1][1]) << '\n';
      }
}