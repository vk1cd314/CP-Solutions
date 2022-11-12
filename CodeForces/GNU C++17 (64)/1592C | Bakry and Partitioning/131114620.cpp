#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
using namespace std;
 
const int N = 1e5 + 10;
vector <int64_t> a(N), subx(N), eq(N);
vector <int> g[N];
bool works = false;
 
void dfs(int u, int p = -1) {
      subx[u] = a[u];
      for (int v : g[u]) if (v ^ p) {
            dfs(v, u);
            subx[u] ^= subx[v];
      }
      debug(u, subx[u]);
}
 
void dfs1(int u, int p = -1) {
      for (int v : g[u]) if (v ^ p) {
            dfs1(v, u);
            eq[u] += eq[v];
      }
      if (eq[u] > 1) works = true;
      if (!subx[u] && eq[u]) works = true;
      eq[u] += subx[u] == subx[0];
      eq[u] = eq[u] > 0;
}
 
int main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
 
      int t; cin >> t;
      while (t--) {
            int n, k; cin >> n >> k;
            for (int i = 0; i <= n; ++i) g[i].clear(), subx[i] = 0, eq[i] = 0;
            for (int i = 0; i < n; ++i) cin >> a[i];
            for (int i = 0; i < n - 1; ++i) {
                  int u, v; cin >> u >> v; --u, --v;
                  g[u].push_back(v);
                  g[v].push_back(u);
            }
            dfs(0);
            debug(vector <int64_t>(subx.begin(), subx.begin() + n));
            debug(vector <int64_t>(a.begin(), a.begin() + n));
            works = false;
            if (!subx[0]) cout << "YES\n";
            else if (k == 2) cout << "NO\n";
            else {
                  dfs1(0);
                  cout << (works ? "YES\n" : "NO\n");
            }
      }
}