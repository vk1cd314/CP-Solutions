#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
using namespace std;
 
int main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
 
      int t; cin >> t;
      while (t--) {
            int n, m; cin >> n >> m;
            int rmax = -1, wmax = -1;
            for (int i = 0; i < m; ++i) {
                  int r, w; cin >> r >> w;
                  rmax = max(r, rmax);
                  wmax = max(w, wmax);
            }
            debug(rmax, wmax);
            if (rmax + wmax > n) {
                  cout << "IMPOSSIBLE\n";
            } else {
                  rmax += n - rmax - wmax;
                  while (rmax--) cout << 'R';
                  while (wmax--) cout << 'W';
                  cout << '\n';
            }
 
 
      }
}