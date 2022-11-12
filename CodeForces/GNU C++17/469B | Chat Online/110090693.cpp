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
 
      int p, q, l, r; cin >> p >> q >> l >> r;
      vector <pair <int, int>> ab, cd;
      bool vis[3333];
      memset(vis, false, sizeof vis);
      for (int i = 0; i < p; ++i) {
            int a, b; cin >> a >> b;
            ab.emplace_back(a, b);
            for (int j = a; j <= b; ++j) vis[j] = true;
      }
      for (int i = 0; i < q; ++i) {
            int c, d; cin >> c >> d;
            cd.emplace_back(c, d);
      }
 
      int ans = 0;
      for (int t = l; t <= r; ++t) {
            bool ok = false;
            for (int i = 0; i < q; ++i) {
                  for (int j = cd[i].first + t; j <= cd[i].second + t; ++j) {
                        if (vis[j]) {
                              ok = true;
                        }
                  }
                  if (ok) break;
            }
            ans += ok;
      }
 
      cout << ans << '\n';
 
      #ifdef Icry
            auto end = std::chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << std::chrono::duration_cast <std::chrono::duration <double>>(end - begin).count() << " seconds]\n";  
      #endif
}