#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
using namespace std;
 
int main() {
      #ifdef Icry
            auto begin = chrono :: high_resolution_clock :: now();
      #endif
      ios_base :: sync_with_stdio(0);
      cin.tie(0);
 
      int t; cin >> t;
      while (t--) {
            int64_t n; cin >> n;
            int64_t lim = 10, tmp = 0, cnt = 0;
            for (int64_t i = 0; i < lim; ++i) {
                  tmp = tmp * 10 + 1;
                  for (int64_t j = 1; j <= 9; ++j) {
                        if (1 <= tmp * j && tmp * j <= n) ++cnt;
                  }
            }
 
            cout << cnt << '\n';
      }
 
      #ifdef Icry
            auto end = chrono :: high_resolution_clock :: now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << chrono :: duration_cast <chrono :: duration <double>> (end - begin).count() << " seconds]\n";  
      #endif
}