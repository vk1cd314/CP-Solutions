#include <bits/stdc++.h>
 
using namespace std;
 
#ifdef SENDHELP
#include "debug.h"
#else
#define debug(args...)
#endif
 
int main() {
      #ifdef SENDHELP
            auto begin = std::chrono::high_resolution_clock::now();
      #endif
      ios_base :: sync_with_stdio(0);
      cin.tie(0);
 
      int t; cin >> t;
      while (t--) {
            int64_t n, k; cin >> n >> k;
            vector <int64_t> p(n); for (auto &x : p) cin >> x;
            int64_t curr = p[0], ans = 0;
            for (int i = 1; i < n; ++i) {
                  if (p[i] * 100LL > k * curr) {
                        int64_t inc = (100LL * p[i] - k * curr + k - 1) / k;
                        curr += inc;
                        ans += inc;
                  }
                  curr += p[i];
            }
            cout << ans << '\n';
      }
 
      #ifdef SENDHELP
            auto end = std::chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << std::chrono::duration_cast <std::chrono::duration <double>>(end - begin).count() << " seconds]\n";  
      #endif
}