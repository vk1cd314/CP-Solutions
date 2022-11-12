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
            
            if (n % 2 == 0) {
                  int64_t ans = k % n;
                  if (ans == 0) ans += n;
                  cout << ans << '\n';
            } else {
                  int64_t jump = n / 2;
                  int64_t ans = ((k - 1) / jump + k) % n;
                  if (ans == 0) ans += n;
                  cout << ans << '\n';
            }
      }
 
      #ifdef SENDHELP
            auto end = std::chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << std::chrono::duration_cast <std::chrono::duration <double>>(end - begin).count() << " seconds]\n";  
      #endif
}