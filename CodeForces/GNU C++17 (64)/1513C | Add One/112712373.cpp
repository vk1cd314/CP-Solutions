#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...)
#endif
 
using namespace std;
 
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
int64_t F[N][11];
 
int main() {
#ifdef Icry
      auto begin = std::chrono::high_resolution_clock::now();
#endif
      ios_base ::sync_with_stdio(0);
      cin.tie(0);
 
      for (int i = 0; i < N; i++) {
            for (int d = 9; d >= 0; d--) {
                  if (i == 0) {
                        F[i][d] = 1;
                  } else {
                        if (d == 9) {
                              F[i][d] = F[i - 1][1] + F[i - 1][0];
                        } else {
                              F[i][d] = F[i - 1][d + 1];
                        }
                  }
                  F[i][d] %= mod;
            }
      }
 
      int t;
      cin >> t;
      while (t--) {
            int64_t n, m; cin >> n >> m;
            int64_t ans = 0;
            while (n) {
                  int64_t rem = n % 10;
                  n /= 10;
                  ans += F[m][rem];
                  ans = ans % mod;
            }
            cout << ans << '\n';
      }
 
#ifdef Icry
      auto end = std::chrono::high_resolution_clock::now();
      cerr << setprecision(4) << fixed;
      cerr << "[Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds]\n";
#endif
}