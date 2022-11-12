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
            map <int, vector <int>> ded;
            int n; cin >> n;
            for (int i = 1; i <= n; ++i) {
                  int x; cin >> x;
                  ded[x].push_back(i);
            }
 
            int ans = -1;
            for (auto [x, y] : ded) {
                  if ((int) y.size() == 1) ans = y[0];
            }
 
            cout << ans << '\n';
      }
 
      #ifdef Icry
            auto end = std::chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << std::chrono::duration_cast <std::chrono::duration <double>>(end - begin).count() << " seconds]\n";  
      #endif
}