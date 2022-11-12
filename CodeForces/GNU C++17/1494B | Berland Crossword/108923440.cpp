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
            int n, u, r, d, l; cin >> n >> u >> r >> d >> l;
 
            if (max({u, r, d, l}) <= n - 2) {
                  cout << "YES\n";
                  continue;
            }
 
            bool ok = false;
            for (int i = 0; i < (1 << 4); ++i) {
                  int aa = 0, bb = 0, cc = 0, dd = 0; //aa - up, bb = right, cc - down, dd - left
                  for (int j = 0; j < 4; ++j) {
                        if (j == 0 && (i & 1 << j)) ++aa, ++dd;
                        if (j == 1 && (i & 1 << j)) ++aa, ++bb;
                        if (j == 2 && (i & 1 << j)) ++cc, ++bb;
                        if (j == 3 && (i & 1 << j)) ++cc, ++dd;
                  }
                  if (u - aa < 0 || r - bb < 0 || d - cc < 0 || l - dd < 0) continue;
                  if (max({u - aa, r - bb, d - cc, l - dd}) <= n - 2) {
                        ok = true;
                        break;
                  }
            }
 
            cout << (ok ? "YES\n" : "NO\n");
      }
 
      #ifdef Icry
            auto end = std::chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << std::chrono::duration_cast <std::chrono::duration <double>>(end - begin).count() << " seconds]\n";  
      #endif
}