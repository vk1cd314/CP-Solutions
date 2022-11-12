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
 
      int a1, a2, k1, k2, n; cin >> a1 >> a2 >> k1 >> k2 >> n;
      int _n = n;
 
      int mi, mx;
      if (k1 < k2) {
            mx = min(a1, n / k1);
            n -= mx * k1;
            mx += min(a2, n / k2);
      } else {
            mx = min(a2, n / k2);
            n -= mx * k2;
            mx += min(a1, n / k1);
            debug(n);
      }
 
      debug(a1, a2, k1, k2, n);
      debug(_n);
      _n -= (k1 - 1) * a1;
      debug(_n);
      _n -= (k2 - 1) * a2;
      debug(_n);
      if (_n < 0) mi = 0;
      else mi = min(a1 + a2, _n);
 
      cout << mi << ' ' << mx << '\n';
 
      #ifdef Icry
            auto end = std::chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << std::chrono::duration_cast <std::chrono::duration <double>>(end - begin).count() << " seconds]\n";  
      #endif
}