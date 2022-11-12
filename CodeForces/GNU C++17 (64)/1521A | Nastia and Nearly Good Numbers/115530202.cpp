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
            int64_t a, b; cin >> a >> b;
            int64_t x, y, z = a * b;
            if (b == 1) {
                  cout << "NO\n";
                  continue;
            }
            if (b == 2) {
                  z = 4LL * a;
                  x = a;
                  y = 3LL * a;
            } else {
                  z = a * b;
                  x = a;
                  y = a * (b - 1);
            }
 
            cout << "YES\n";
            cout << x <<' ' << y << ' ' << z << '\n';
 
      }
 
      #ifdef Icry
            auto end = chrono :: high_resolution_clock :: now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << chrono :: duration_cast <chrono :: duration <double>> (end - begin).count() << " seconds]\n";  
      #endif
}