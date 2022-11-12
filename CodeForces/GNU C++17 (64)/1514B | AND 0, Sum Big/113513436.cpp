#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
using namespace std;
 
const int mod = 1e9 + 7;
 
int main() {
      #ifdef Icry
            auto begin = chrono :: high_resolution_clock :: now();
      #endif
      ios_base :: sync_with_stdio(0);
      cin.tie(0);
 
      int t; cin >> t;
      while (t--) {
            int64_t n, k; cin >> n >> k;
 
            // if (n == 1 || k == 1) {
            //       cout << "1\n";
            //       continue;
            // }     
 
            // int64_t mx = (1 << k) - 1, cnt = 0;
            // for (int64_t i = 0; i < (1 << k); ++i) {
            //       if ((i & (mx - i)) == 0) ++cnt;
            // }
 
            // debug(cnt);
            // // assert(cnt % 2 == 0);
            // cnt -= 2;
            // // cnt /= 2;
            // int64_t ans = (n + ((n * (n - 1)) * cnt) % mod) % mod;
            // cout << ans << '\n';
 
            int64_t ans = 1;
            for (int i = 0; i < k; ++i) ans = (ans * n) % mod;
 
            cout << ans << '\n';
      }
 
      #ifdef Icry
            auto end = chrono :: high_resolution_clock :: now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << chrono :: duration_cast <chrono :: duration <double>> (end - begin).count() << " seconds]\n";  
      #endif
}