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
            vector <string> g(n);
            for (auto &x : g) cin >> x;
            auto go = [&](int i, int j) {
                  while (i < n - 1) {
                        if (g[i + 1][j] == 'o') break;
                        if (g[i + 1][j] == '*') break;
                        g[i][j] = '.';
                        g[i + 1][j]  = '*';
                        i++;
                  }
            };
            for (int i = n - 1; i >= 0; --i) {
                  for (int j = m - 1; j >= 0; --j) {
                        if (g[i][j] == '*') go(i, j);
                  }
            }
            for (auto s : g) cout << s << '\n';
            cout << '\n';
      }
}