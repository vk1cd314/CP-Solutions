#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
using namespace std;
 
const int N = 2e5 + 10;
vector <int> g[N];
bool vis[N];
bool ok = true;
 
void dfs(int u, int d = 0) {
      vis[u] = true;
      ok &= g[u].size() == 2;
      for (int v : g[u]) {
            if (!vis[v]) dfs(v, d + 1);
      }
}
 
int main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
 
      int n, m; cin >> n >> m;
      for (int i = 0; i < m; ++i) {
            int u, v; cin >> u >> v;
            --u, --v;
            g[u].push_back(v);
            g[v].push_back(u);
      }
      int ans = 0;
      for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                  ok = true;
                  dfs(i);
                  if (ok) ans++; 
            }
      }
      cout << ans << '\n';
}