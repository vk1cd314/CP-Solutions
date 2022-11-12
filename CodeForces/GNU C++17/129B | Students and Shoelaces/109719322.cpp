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
 
      set <int> g[110];
      int n, m; cin >> n >> m;
      for (int i = 0; i < m; ++i) {
            int u, v; cin >> u >> v;
            g[u].insert(v);
            g[v].insert(u);
      }
 
      int cnt = 0;
      while (3) {
            vector <int> dd;
            for (int i = 0; i < 110; ++i) {
                  if ((int) g[i].size() == 1) dd.push_back(i);
            }
            if (dd.empty()) break;
            for (int x : dd) {
                  if (g[x].empty()) continue;
                  if (g[*g[x].begin()].count(x)) g[*g[x].begin()].erase(x);
                  g[x].clear();
            } 
            ++cnt;
      }
 
      cout << cnt << '\n';
 
      #ifdef Icry
            auto end = std::chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << std::chrono::duration_cast <std::chrono::duration <double>>(end - begin).count() << " seconds]\n";  
      #endif
}