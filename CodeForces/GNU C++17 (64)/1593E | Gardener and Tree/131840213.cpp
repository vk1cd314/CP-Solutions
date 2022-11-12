#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
using namespace std;
 
const int N = 4e5 + 10;
set <int> g[N];
 
int main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
 
      int t; cin >> t;
      while (t--) {
            int n, k; cin >> n >> k;
            for (int i = 0; i <= n; ++i) g[i].clear();
            int nodes = n;
            vector <int> deg(n + 1, 0);
            for (int i = 0; i < n - 1; ++i) {
                  int u, v; cin >> u >> v;
                  g[u].insert(v);
                  g[v].insert(u);
                  deg[u]++;
                  deg[v]++;
            }
            if (n == 1) {
                  cout << 0 << '\n';
                  continue;
            }
            set <int> zz;
            for (int i = 1; i <= n; ++i) {
                  if (deg[i] == 1) zz.insert(i);
            }
            k = min(k, 2 * n);
            while (k--) {
                  set <int> nw;
                  for (int u : zz) {
                        deg[u] = 0;
                        for (int v : g[u]) {
                              deg[v]--;
                              if (deg[v] == 1 || deg[v] == 0) nw.insert(v);
                              g[v].erase(u);
                        }
                        g[u].clear();
                  }
                  if (nodes > 0) nodes -= zz.size();
                  zz = nw;
            }
            debug(deg);
            cout << nodes << '\n';
      }
}