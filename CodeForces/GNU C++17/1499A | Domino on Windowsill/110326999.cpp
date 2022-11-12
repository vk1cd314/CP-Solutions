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
            int n, k1, k2; cin >> n >> k1 >> k2;
            int w, b; cin >> w >> b;
            int mx1 = min(k1, k2) + abs(k1 - k2) / 2;
            int mx2 = min(n - k1, n - k2) + abs(n - k1 - (n - k2)) / 2;
            if (mx1 >= w && mx2 >= b) cout << "YES\n";
            else cout <<"NO\n";
      }
 
      #ifdef Icry
            auto end = std::chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << std::chrono::duration_cast <std::chrono::duration <double>>(end - begin).count() << " seconds]\n";  
      #endif
}