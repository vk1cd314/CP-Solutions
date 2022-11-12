#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
using namespace std;
 
const int N = 2e5 + 10;
vector <int> g[N];
bool vis[N], vis2[N];
bool welp = false, bad = false;
int nodes = 0;
int deg[N], col[N];
map <int, int> ff[N];
 
void dfs(int u, int c) {
      vis[u] = true;
      col[u] = c;
      if (deg[u] > 2) {
            bad = true;
      }
      ++nodes;
      for (int v : g[u]) {
            if (!vis[v]) {
                  if (c == 1) dfs(v, 2);
                  else dfs(v, 1);
            }
            if (col[u] == col[v]) bad = true;
            if (ff[u][v] > 1) {
                  welp = true;
            }
      }
}
 
int main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
 
      int t; cin >> t;
      while (t--) {
            int n; cin >> n;
            memset(vis, 0, sizeof(vis[0]) * (n + 5));
            memset(deg, 0, sizeof(deg[0]) * (n + 5));
            memset(col, 0, sizeof(col[0]) * (n + 5));
 
            for (int i = 0; i <= n + 5; ++i) g[i].clear(), ff[i].clear();
            bool ok = true;
            for (int i = 0; i < n; ++i) {
                  int a, b; cin >> a >> b;
                  if (a == b) {
                        ok = false;
                        continue;
                  }
                  if (a > b) swap(a, b);
                  g[a].push_back(b);
                  g[b].push_back(a);
                  ff[a][b]++;
                  ff[b][a]++;
                  deg[a]++;
                  deg[b]++;
                  if (ff[a][b] > 2) ok = false;
            }
            for (int i = 1; i <= n; ++i) {
                  bad = false;
                  welp = false;
                  nodes = 0;
                  if (!vis[i]) {
                        dfs(i, 1);
                        if (bad) {
                              ok = false;
                        }
                        if (welp) {
                              if (nodes != 2) ok = false;
                        }
                  }
            }
            cout << (ok ? "YES\n" : "NO\n");
      }
}