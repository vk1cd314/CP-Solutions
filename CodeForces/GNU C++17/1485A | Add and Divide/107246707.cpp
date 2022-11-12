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
            int64_t a, b; cin >> a >> b;
            
            int64_t ans = INT_MAX;
            for (int i = b == 1 ? b + 1 : b; i < b + 30; ++i) {
                  int nw = 0;
                  int64_t _a = a;
                  while(_a) _a /= i, ++nw;
                  ans = min(ans, i - b + nw);
            }
 
            cout << ans << '\n';
      }
 
      #ifdef SENDHELP
            auto end = std::chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << std::chrono::duration_cast <std::chrono::duration <double>>(end - begin).count() << " seconds]\n";  
      #endif
}