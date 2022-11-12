#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
using namespace std;
 
const int N = 2e5 + 10;
set <int> g[N];
 
int main() {
      #ifdef Icry
            auto begin = chrono::high_resolution_clock::now();
      #endif
      ios_base::sync_with_stdio(0);
      cin.tie(0);
 
      int n, m; cin >> n >> m;
 
      while (m--) {
            int u, v; cin >> u >> v;
            if (u < v) g[u].insert(v);
            if (v < u) g[v].insert(u);
      }
 
      set <int> zeros;
      for (int x = 1; x <= n; ++x) {
            if (g[x].empty()) zeros.insert(x);
      }
      int q; cin >> q;
      while (q--) {
            int t; cin >> t;
            if (t == 1) {
                  int u, v; cin >> u >> v;
                  if (u < v) {
                        g[u].insert(v);
                        auto it = zeros.find(u);
                        if (it != zeros.end()) zeros.erase(it);
                  }
                  if (v < u) {
                        g[v].insert(u);
                        auto it = zeros.find(v);
                        if (it != zeros.end()) zeros.erase(it);
                  }
            } else if (t == 2) {
                  int u, v; cin >> u >> v;
                  if (u < v) {
                        g[u].erase(g[u].find(v));
                        if (g[u].empty()) zeros.insert(u);
                  }
                  if (v < u) {
                        g[v].erase(g[v].find(u));
                        if (g[v].empty()) zeros.insert(v);
                  }
            } else {
                  cout << zeros.size() << '\n';
            }
      }
 
      #ifdef Icry
            auto end = chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << chrono::duration_cast <chrono :: duration <double>> (end - begin).count() << " seconds]\n";  
      #endif
}