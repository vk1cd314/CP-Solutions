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
            int n, m, k; cin >> n >> m >> k;
            vector <string> a(n); for (auto &s : a) cin >> s;
            set <pair <int, int>> pps, apps;
            for (int i = 0; i < n; ++i) {
                  for (int j = 0; j < m; ++j) {
                        if (a[i][j] == '*') {
                              pps.insert({i, j});
                        }
                  }
            }
 
            for (int i = 0; i < n; ++i) {
                  for (int j = 0; j < m; ++j) {
                        if (a[i][j] == '*') {
                              int ii = i, jj = j;
                              vector <pair <int, int>> pts;
                              pts.push_back({i, j});
                              while (ii + 1 < n && jj + 1 < m && a[ii + 1][jj + 1] == '*') {
                                    pts.push_back({ii + 1, jj + 1});
                                    ++ii, ++jj;
                                    if (ii - 1 >= 0 && jj + 1 < m && a[ii - 1][jj + 1] == '*') {
                                          int iii = ii, jjj = jj;
                                          int have = int(pts.size()) - 1;
                                          if (have >= k) {
                                                vector <pair <int, int>> cc;
                                                while (iii - 1 >= 0 && jjj + 1 < m && a[iii - 1][jjj + 1] == '*') {
                                                      cc.push_back({iii - 1, jjj + 1});
                                                      if ((int) cc.size() == have) {
                                                            for (auto p : pts) apps.insert(p);
                                                            for (auto p : cc) apps.insert(p);
                                                      }
                                                      iii--, jjj++;
                                                }
                                          }
                                    }
                              }
                        }
                  }
            }
 
            cout << (apps == pps ? "YES\n" : "NO\n"); 
      }
}