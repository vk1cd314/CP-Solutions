#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif

using namespace std;

const int N = 3e3 + 10;
vector <int> g[N];
bool vis[N];

void dfs(int u) {
      debug(u);
      vis[u] = true;
      for (int v : g[u]) {
            if (!vis[v]) dfs(v);
      }
}

int main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);

      int n; cin >> n;
      int sx, sy, tx, ty; cin >> sx >> sy >> tx >> ty;
      vector <tuple <int, int, long long>> xx(n);
      for (int i = 0; i < n; ++i) {
            auto &[x, y, r] = xx[i];
            cin >> x >> y >> r;
      }

      debug(sx, sy, tx, ty);

      int st = -1, ed = -1;
      for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                  int x1, y1;
                  long long r1;
                  tie(x1, y1, r1) = xx[i];
                  int x2, y2;
                  long long r2;
                  tie(x2, y2, r2) = xx[j];
                  long long dd = 1ll * (x1 - x2) * (x1 - x2) + 1ll * (y1 - y2) * (y1 - y2);
                  long long rad = (r1 + r2) * (r1 + r2);
                  long long rad1 = (r1 - r2) * (r1 - r2);
                  debug(i, j, dd, rad);
                  if (rad1 <= dd and dd <= rad) {
                        g[i].push_back(j);
                        g[j].push_back(i);
                  }
            }
            int x1, y1;
            long long r1;
            tie(x1, y1, r1) = xx[i];
            if (1ll * (sx - x1) * (sx - x1) + 1ll * (sy - y1) * (sy - y1) == r1 * r1) {
                  st = i;
            }
            if (1ll * (tx - x1) * (tx - x1) + 1ll * (ty - y1) * (ty - y1) == r1 * r1) {
                  ed = i;
            }
      } 

      debug(st, ed);

      dfs(st);
      if (vis[ed]) cout << "Yes\n";
      else cout << "No\n";
}
// 