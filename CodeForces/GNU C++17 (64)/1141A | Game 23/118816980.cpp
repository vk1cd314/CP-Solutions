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
 
      int64_t n, m; cin >> n >> m;
      if (m % n) {
            cout << -1 << '\n';
            return 0;
      }
      int64_t huh = m / n;
      int c2 = 0, c3 = 0;
      while (huh % 2 == 0) c2++, huh /= 2;
      while (huh % 3 == 0) c3++, huh /= 3;
 
      if (huh != 1) {
            cout << -1 << '\n';
            return 0;
      }
 
      cout << c2 + c3 << '\n';
 
 
      #ifdef Icry
            auto end = chrono :: high_resolution_clock :: now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << chrono :: duration_cast <chrono :: duration <double>> (end - begin).count() << " seconds]\n";  
      #endif
}