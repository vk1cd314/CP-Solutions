#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
using namespace std;
 
const int N = 1e5 + 10, mod = 1e9 + 7, inv2 = mod + 1 >> 1;
int dp[2][N], pref[N];
 
// int go(bool type, int i) {
//       if (i > n) return 0;
//       if (i == n) return 1;
 
//       int &ret = dp[type][i];
//       if (~ret) return ret;
 
//       ret = 0;
//       if (type) {
//             ret += go(type, i + k);
//             ret += go(type ^ 1, i + k);
//       } else {
//             ret += go(type, i + 1);
//             ret += go(type ^ 1, i + 1);
//       }
 
//       return ret;
// }
 
/*
 * dp[0][N] = dp[1][N] = 1;   
 * dp[0][i] = dp[1][i + 1] + dp[0][i + 1]
 * dp[1][i] = dp[1][i + k] + dp[0][i + k]
 * 
 * dp[0][0] = dp[1][0] = 1;
 * dp[0][i] = dp[1][i - 1] + dp[0][i - 1]
 * dp[1][i] = dp[1][i - k] + dp[0][i - k]
 */
 
int main() {
      #ifdef Icry
            auto begin = chrono :: high_resolution_clock :: now();
      #endif
      ios_base :: sync_with_stdio(0);
      cin.tie(0);
 
      // memset(dp[0], -1, sizeof dp[0]);
      // memset(dp[1], -1, sizeof dp[1]);
      // cout << (go(0, 0) + go(1, 0)) / 2 << '\n';
 
      int t, k; cin >> t >> k;
 
      dp[0][0] = dp[1][0] = 1;
      for (int i = 1; i < N; ++i) {
            dp[0][i] = (dp[0][i - 1] + dp[1][i - 1]) % mod;
            if (i - k >= 0) dp[1][i] = (dp[1][i - k] + dp[0][i - k]) % mod;
            // debug((dp[0][i] + dp[1][i]) / 2);
      }
 
      for (int i = 1; i < N; ++i) {
            pref[i] = pref[i - 1];
            int64_t toAdd = (dp[0][i] + dp[1][i]) % mod;
            toAdd = (int64_t) toAdd * inv2 % mod;
            pref[i] = (pref[i] + toAdd) % mod;
            // debug(pref[i]);
      }
 
      while (t--) {
            int a, b; cin >> a >> b;
            cout << ((pref[b] - pref[a - 1]) % mod + mod) % mod << '\n';
      }
      // Didn't mod correctly ;-;
 
      #ifdef Icry
            auto end = chrono :: high_resolution_clock :: now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << chrono :: duration_cast <chrono :: duration <double>> (end - begin).count() << " seconds]\n";  
      #endif
}