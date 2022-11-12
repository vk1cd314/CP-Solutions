#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...)
#endif
 
using namespace std;
 
const int N = 2e5 + 10;
int dep[N];
 
int n, l;
vector<vector<int>> adj;
 
int timer;
vector<int> tin, tout;
vector<vector<int>> up;
 
void dfs(int v, int p, int d = 0) {
      tin[v] = ++timer;
      up[v][0] = p;
      for (int i = 1; i <= l; ++i)
            up[v][i] = up[up[v][i - 1]][i - 1];
      dep[v] = d;
      debug(v, p);
      for (int u : adj[v]) {
            if (u != p)
                  dfs(u, v, d + 1);
      }
 
      tout[v] = ++timer;
}
 
bool is_ancestor(int u, int v) {
      return tin[u] <= tin[v] && tout[u] >= tout[v];
}
 
int lca(int u, int v) {
      if (is_ancestor(u, v))
            return u;
      if (is_ancestor(v, u))
            return v;
      for (int i = l; i >= 0; --i) {
            if (!is_ancestor(up[u][i], v))
                  u = up[u][i];
      }
      return up[u][0];
}
 
int dist(int u, int v) {
      return dep[u] + dep[v] - 2 * dep[lca(u, v)];
}
 
void preprocess(int root) {
      tin.resize(n);
      tout.resize(n);
      timer = 0;
      l = ceil(log2(n));
      up.assign(n, vector<int>(l + 1));
      dfs(root, root);
}
 
int main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
 
      cin >> n;
      adj.assign(n + 2, {});
      for (int i = 0; i < n - 1; ++i) {
            int u, v; cin >> u >> v;
            --u, --v;
            adj[u].push_back(v);
            adj[v].push_back(u);
      }
      debug(11);
      preprocess(0);
      int q; cin >> q;
      while (q--) {
            int k; cin >> k;
            vector <int> pp(k); for (int &x : pp) cin >> x, --x;
            debug(pp);
            debug("3333");
            sort(pp.begin(), pp.end(), [&](int a, int b) {
                  return dep[a] < dep[b];
            });
            set <int> lol;
            int c1 = pp.back();
            int mx = -1;
            for (int i = 0; i < k - 1; ++i) {
                  int di = dist(pp.back(), pp[i]);
                  if (di > mx) {
                        mx = di;
                        c1 = pp[i];
                  } 
            }
            int la = lca(pp.back(), c1);
            debug(c1, pp.back(), la);
            int curr = pp.back();
            while (curr != la) {
                  lol.insert(curr);
                  curr = up[curr][0];
            }
            curr = c1;
            while (curr != la) {
                  lol.insert(curr);
                  curr = up[curr][0];
            }
            lol.insert(la);
            debug(lol);
            bool ok = true;
            for (int i = 0; i < k; ++i) {
                  if (!lol.count(pp[i])) ok = false;
            } 
            cout << (ok ? "YES\n" : "NO\n");
      }
}