#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
using namespace std;
 
// struct DSU {
//       vector <int> par, rank;
 
//       DSU(int n) {
//             par.assign(n, 0);
//             iota(par.begin(), par.end(), 0);
//             rank.assign(n, 0);
//       }
 
//       int find(int x) {
//             if (par[x] == x) return x;
//             return par[x] = find(par[x]);
//       }
 
//       bool unite(int u, int v) {
//             u = find(u), v = find(v);
//             if (u == v) return false;
//             if (rank[u] > rank[v]) swap(u, v);
//             par[u] = v;
//             if (rank[u] == rank[v]) rank[v]++;
//             return true;
//       }
// };
 
 
int main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
 
      int t; cin >> t;
      while (t--) {
            int n; cin >> n;
            vector <int> p(n); for (int &x : p) cin >> x;
            int ans = 0;
            vector <int> pre(n);
            pre[0] = p[0];
            for (int i = 1; i < n; ++i) {
                  pre[i] = max(pre[i - 1], p[i]);
            }
            for (int i = 0; i < n; ++i) ans += pre[i] == i + 1;
            cout << ans << '\n';
      }
}
// 4 2 1 7 6 5 3 