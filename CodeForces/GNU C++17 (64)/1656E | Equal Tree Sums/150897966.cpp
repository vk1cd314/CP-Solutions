#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
using namespace std;
 
const int N = 1e5 + 10;
vector <int> g[N];
int col[N];
 
void dfs(int u, int p = -1, int c = 0) {
      col[u] = c;
      for (int v : g[u]) if (v ^ p) dfs(v, u, c ^ 1);
}
 
int main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
 
      int t; cin >> t;
      while (t--) {
            int n; cin >> n;
            memset(col, 0, sizeof col);
            for (int i = 0; i < n; ++i) g[i].clear();
            for (int i = 0; i < n - 1; ++i) {
                  int u, v; cin >> u >> v;
                  g[--u].push_back(--v);
                  g[v].push_back(u);
            }
            dfs(0);
            for (int i = 0; i < n; ++i) {
                  cout << (col[i] ? (int) g[i].size() : - (int) g[i].size()) << ' ';
            }
            cout << '\n';
      }
}