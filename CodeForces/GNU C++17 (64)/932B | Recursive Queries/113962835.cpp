#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
using namespace std;
 
const int N = 1e6 + 10;
int dp[N][10];
 
int main() {
      #ifdef Icry
            auto begin = chrono :: high_resolution_clock :: now();
      #endif
      ios_base :: sync_with_stdio(0);
      cin.tie(0);
 
 
      // map <int, int> cnt;
      for (int i = 1; i < N; ++i) {
            int x = i;
            while (x > 9) {
                  int prod = 1;
                  for (char c : to_string(x)) {
                        if (c != '0') prod *= (c - '0');
                  }
                  x = prod;
            }
            // cnt[x]++;
            for (int j = 1; j < 10; ++j) dp[i][j] = dp[i - 1][j];
            dp[i][x]++;
      }
 
      int q; cin >> q;
      while (q--) {
            int l, r, k; cin >> l >> r >> k;
            cout << dp[r][k] - dp[l - 1][k] << '\n';
      }
 
      #ifdef Icry
            auto end = chrono :: high_resolution_clock :: now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << chrono :: duration_cast <chrono :: duration <double>> (end - begin).count() << " seconds]\n";  
      #endif
}