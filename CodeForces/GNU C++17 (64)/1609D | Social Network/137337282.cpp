#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
using namespace std;
 
struct DSU {
      int n;
      vector <int> p, sz, ext, pts;
      DSU() {}
      DSU(int _n) : n(_n) {
            p.resize(n);
            sz.resize(n, 1);
            iota(p.begin(), p.end(), 0);
      }
      int find(int u) {
            return (u == p[u] ? u : find(p[u]));
      }
      bool unite(int u, int v) {
            u = find(u), v = find(v);
            if (u == v) return false;
            if (sz[u] < sz[v]) swap(u, v);
            p[v] = u;
            sz[u] += sz[v];
            return true;
      }
};
 
int main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
 
      int n, d; cin >> n >> d;
      DSU daa(n + 1);
      int ext = 1;
      while (d--) {
            int x, y; cin >> x >> y;
            ext += !daa.unite(x, y);
            vector <int> pp;
            for (int i = 1; i <= n; ++i) {
                  if (daa.p[i] == i) {
                        pp.push_back(daa.sz[i]);
                  }
            }
            sort(pp.begin(), pp.end());
            int aa = 0;
            for (int i = 0; i < ext && !pp.empty(); ++i) {
                  aa += pp.back(); pp.pop_back();
            }
            cout << aa - 1 << '\n';
      }
}     