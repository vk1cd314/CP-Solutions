#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
using namespace std;
 
const int N = 1010;
const int64_t mod = 1e9 + 7;
int64_t dp[N][N][3], n, k;
 
int64_t rec(int i, int j, int f) {
      if (f == 0) {
            if (i > n) return 1;
      } else {
            if (i == 0) return 1;
      }
 
      if (dp[i][j][f] != -1) return dp[i][j][f];
      dp[i][j][f] = 0;
      if (!f) {
            if (i <= n) dp[i][j][f] = (rec(i + 1, j, f)) % mod;
            if (j > 1 && i > 0) dp[i][j][f] = (dp[i][j][f] + rec(i - 1, j - 1, f ^ 1)) % mod;
      } else {
            if (i > 0) dp[i][j][f] = (rec(i - 1, j, f)) % mod;
            if (j > 1 && i <= n) dp[i][j][f] = (dp[i][j][f] + rec(i + 1, j - 1, f ^ 1)) % mod; 
      }
      return dp[i][j][f];
}
 
int main() {
      #ifdef Icry
            auto begin = std::chrono::high_resolution_clock::now();
      #endif
      ios_base :: sync_with_stdio(0);
      cin.tie(0);
 
      int t; cin >> t;
      while (t--) {
            cin >> n >> k;
            memset(dp, -1, sizeof dp);
            // D(n, k) = D(0, k - 1) + D(1, k - 2) + ...
            // D(0, k) = 1
            cout << rec(0, k, 0) << '\n';
      }
 
      #ifdef Icry
            auto end = std::chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << std::chrono::duration_cast <std::chrono::duration <double>>(end - begin).count() << " seconds]\n";  
      #endif
}
 
// if (f == 0) ret += rec(i + 1, j, f) + rec(i - 1, j - 1, f ^ 1);