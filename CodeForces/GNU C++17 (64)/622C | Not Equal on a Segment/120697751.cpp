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
            par.resize(n);
            iota(par.begin(), par.end(), 0);
            rank.resize(n);
      }
 
      int find(int x) {
            if (par[x] == x) return x;
            return par[x] = find(par[x]);
      }
 
      bool unite(int u, int v) {
            u = find(u), v = find(v);
            if (u == v) return false;
            // if (rank[u] > rank[v]) swap(u, v);
            par[u] = v;
            if (rank[u] == rank[v]) rank[v]++;
            return true;
      }
};
const int N = 2e5 + 2;
int a[N];
 
int main() {
      #ifdef Icry
            auto begin = chrono::high_resolution_clock::now();
      #endif
      ios_base::sync_with_stdio(0);
      cin.tie(0);
 
      int n, m; cin >> n >> m;
      for (int i = 1; i <= n; ++i) cin >> a[i]; 
      DSU ds(n + 1);
      for (int i = 1; i + 1 <= n; ++i) {
            if (a[i] == a[i + 1]) ds.unite(i, i + 1);
      }
 
      while (m--) {
            int l, r, x; cin >> l >> r >> x;
 
            if (a[l] != x) {
                  cout << l << '\n';
                  continue;
            }
 
            int par = ds.find(l);
            if (par - l + 1 >= r - l + 1) cout << "-1\n";
            else cout << par + 1 << '\n';
      }
 
      #ifdef Icry
            auto end = chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << chrono::duration_cast <chrono :: duration <double>> (end - begin).count() << " seconds]\n";  
      #endif
}