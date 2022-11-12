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
            
            int left = -1;
            for (int64_t i = 33; i >= 0; --i) {
                  if (n & (1LL << i)) {
                        left = i;
                        break;
                  }
            }
            int64_t ans = 0;
            for (int64_t i = left - 1; i >= 0; --i) {
                  ans += (1LL << i);
            }
 
            cout << ans << '\n';
      }
 
      #ifdef Icry
            auto end = chrono :: high_resolution_clock :: now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << chrono :: duration_cast <chrono :: duration <double>> (end - begin).count() << " seconds]\n";  
      #endif
}