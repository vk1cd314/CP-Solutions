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
            vector <vector <int>> g(n, vector <int>(m, 0));
            int ct = 0;
            for (int i = 0; i < n; i += 2) {
                  int l = ct % 2;
                  for (int j = 0; j < m; j += 2) {
                        if (l % 2 == 0) {
                              g[i][j] = 1;
                              g[i + 1][j] = 0;
                              g[i][j + 1] = 0;
                              g[i + 1][j + 1] = 1;
                        } else {
                              g[i][j] = 0;
                              g[i + 1][j] = 1;
                              g[i][j + 1] = 1;
                              g[i + 1][j + 1] = 0;
                        }
                        l++;
                  }
                  ct++;
            }
            for (auto v : g) {
                  for (int x : v) cout << x << ' ';
                  cout << '\n';
            }
      }
}