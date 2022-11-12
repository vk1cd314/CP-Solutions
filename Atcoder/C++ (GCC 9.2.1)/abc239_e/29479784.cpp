#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif

using namespace std;

const int N = 1e5 + 10;
vector <int> g[N];
vector <int> sub[N];
int x[N];

//  return max 20 values
vector <int> dfs(int u, int p) {
      vector <int> ret;
      ret.push_back(x[u]);
      for (int v : g[u]) {
            if (v != p) {
                  vector <int> tmp = dfs(v, u);
                  for (int xx : tmp) ret.push_back(xx); 
            }
      }
      sort(ret.rbegin(), ret.rend());
      while ((int) ret.size() > 20) ret.pop_back();
      sub[u] = ret;
      return ret;
}

int main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);

      int n, q; cin >> n >> q;
      for (int i = 1; i <= n; ++i) cin >> x[i]; 
      for (int i = 0; i < n - 1; ++i) {
            int u, v; cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
      }
      dfs(1, -1);
      for (int i = 1; i <= n; ++i) {
            debug(sub[i]);
      }
      while (q--) {
            int v, k; cin >> v >> k;
            cout << sub[v][k - 1] << '\n'; 
      }
}