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
            int64_t p, a, b, c; cin >> p >> a >> b >> c;
            int64_t a1 = (p + a - 1) / a, a2 = (p + b - 1) / b, a3 = (p + c - 1) / c;
            cout << min({a1 * a - p, a2 * b - p, a3 * c - p}) << '\n';
      }
 
      #ifdef SENDHELP
            auto end = std::chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << std::chrono::duration_cast <std::chrono::duration <double>>(end - begin).count() << " seconds]\n";  
      #endif
}