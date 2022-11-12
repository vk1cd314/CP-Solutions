#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
using namespace std;
 
int main() {
      #ifdef Icry
            auto begin = std::chrono::high_resolution_clock::now();
      #endif
      ios_base :: sync_with_stdio(0);
      cin.tie(0);
 
      int t; cin >> t;
      while (t--) {
            int64_t n, k; cin >> n >> k;
            for (int i = 0; i < k - 3; ++i) cout << "1 ";
            n -= k - 3;
            int64_t i = 1;
            while (3) {
                  if (n - i > 0 && (n - i) % 2 == 0) {
                        if (lcm(lcm(i, (n - i) / 2), (n - i) / 2) * 2 <= n) {
                              cout << i << ' ' << (n - i) / 2 << ' ' << (n - i) / 2 << '\n';
                              break;
                        }
                  } 
                  ++i;
            }
      }
 
      #ifdef Icry
            auto end = std::chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << std::chrono::duration_cast <std::chrono::duration <double>>(end - begin).count() << " seconds]\n";  
      #endif
}