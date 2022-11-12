#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
using namespace std;
 
struct DSU {
      vector <int> par, rank;
 
      DSU(int n) {
            par.assign(n, 0);
            iota(par.begin(), par.end(), 0);
            rank.assign(n, 0);
      }
 
      int find(int x) {
            if (par[x] == x) return x;
            return par[x] = find(par[x]);
      }
 
      bool unite(int u, int v) {
            u = find(u), v = find(v);
            if (u == v) return false;
            if (rank[u] > rank[v]) swap(u, v);
            par[u] = v;
            if (rank[u] == rank[v]) rank[v]++;
            return true;
      }
};
 
bool a[169][169];
 
int main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
 
      int n, m; cin >> n >> m;
      bool zero = true;
      for (int i = 0; i < n; ++i) {
            int k; cin >> k;
            if (k) zero = false; 
            for (int j = 0; j < k; ++j) {
                  int x; cin >> x;
                  a[i][x] = true;
            }
      }
 
      DSU d(n + 1);
      for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                  for (int k = 1; k <= m; ++k) {
                        if (a[i][k] && a[j][k]) {
                              d.unite(i, j);
                              break;
                        }
                  }
            }
      }
 
      int cmp = 0;
      for (int i = 0; i < n; ++i) {
            cmp += d.find(i) == i;
            if (d.find(i) == i) {
                  debug(d.find(i));
            }
      }
      cout << cmp - !zero << '\n';
}