#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
using namespace std;
 
int main() {
      #ifdef Icry
            auto begin = chrono :: high_resolution_clock :: now();
      #endif
      ios_base :: sync_with_stdio(0);
      cin.tie(0);
 
      int t; cin >> t;
      while (t--) {
            int n, m; cin >> n >> m;
            vector <vector <int64_t>> a(n, vector <int64_t>(m));
            for (auto &x : a) for (auto &y : x) cin >> y;
 
            vector <tuple <int, int, int>> succ;
            for (int i = 0; i < n; ++i) {
                  for (int j = 0; j < m; ++j) {
                        succ.push_back({a[i][j], i, j});
                  }
            }
 
            sort(succ.begin(), succ.end());
 
            map <pair <int, int>, int> done;
            vector <vector <int>> ans(n, vector <int>(m, -1));
            for (int i = 0; i < m; ++i) {
                  ans[get <1>(succ[i])][i] = get <0>(succ[i]);
                  done[{get <1>(succ[i]), get <2>(succ[i])}] = 1;
            }
 
            for (int i = 0; i < n; ++i) {
                  for (int j = 0; j < m; ++j) {
                        if (ans[i][j] == -1) {
                              for (int k = 0; k < m; ++k) {
                                    if (!done[{i, k}]) {
                                          ans[i][j] = a[i][k];
                                          done[{i, k}] = 1;
                                          break;
                                    }
                              }
                        }
                  }
            }
 
            for (int i = 0; i < n; ++i) {
                  for (int j = 0; j < m; ++j) {
                        cout << ans[i][j] << ' ';
                  }
                  cout << '\n';
            }            
      }
 
      #ifdef Icry
            auto end = chrono :: high_resolution_clock :: now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << chrono :: duration_cast <chrono :: duration <double>> (end - begin).count() << " seconds]\n";  
      #endif
}