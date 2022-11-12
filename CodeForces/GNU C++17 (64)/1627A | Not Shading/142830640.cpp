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
            int n, m, r, c; cin >> n >> m >> r >> c;
            vector <string> a(n);
            for (auto &s : a) cin >> s;
            --r, --c;
            bool ok = false;
            int ct = 0;
            vector <pair <int, int>> pp;
            for (int i = 0; i < n; ++i) {
                  for (int j = 0; j < m; ++j) {
                        ct += a[i][j] == 'B';
                        if (a[i][j] == 'B') {
                              pp.push_back({i, j});
                              if (i == r && j == c) ok = true;
                        }
                  }
            }
            if (!ct) cout << "-1\n";
            else if (ok) {
                  cout << "0\n";
            } else {
                  bool now = false;
                  for (auto [x, y] : pp) {
                        if (r == x || c == y) now = true;
                  }
                  cout << (now ? "1\n" : "2\n");
            }
      }
}