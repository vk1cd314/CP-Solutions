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
            int64_t n; cin >> n;
            
            int cnt = 0;
            int64_t val = 3;
            while (val * val <= 2 * n + 1) {
                  if (val * val == 2 * n + 1) --cnt; // as c = a ^ 2 - b = b + 1 & if b = n then c = n + 1
                  ++cnt, val += 2;
            }
 
            cout << cnt << '\n';
      }
 
      #ifdef SENDHELP
            auto end = std::chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << std::chrono::duration_cast <std::chrono::duration <double>>(end - begin).count() << " seconds]\n";  
      #endif
}
 