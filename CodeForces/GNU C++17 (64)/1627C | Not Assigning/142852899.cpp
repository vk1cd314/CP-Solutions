#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
using namespace std;
 
const int N = 1e6;
// vector <int> primes;
// bitset <N> prim;
vector <int> g[N];
map <pair <int, int>, int> ss;
int ed;
 
// void sieve() {      
//       prim[1] = 1;
//       for (int i = 2; i * i < N; ++i) {
//             if (!prim[i]) {
//                   for (int j = i * i; j < N; j += i) {
//                         prim[j] = 1;
//                   }
//             }
//       }
 
//       // for (int i = 2; i < N; ++i) {
//       //       if (!prim[i]) primes.push_back(i);
//       // }
// }
 
void dfs(int u, int p, int c) {
      for (int v : g[u]) {
            if (v == p) continue;
            ss[{u, v}] = c;
            ss[{v, u}] = c;
            if (c == 2) dfs(v, u, 3);
            else dfs(v, u, 2);
      }
}
 
void dfs1(int u, int p) {
      ed = u;
      for (int v : g[u]) {
            if (v == p) continue;
            dfs1(v, u);
      }
}
 
int main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
 
      // sieve();
      // vector <int> ops;
      // for (int i = 1; i <= (int)(1e5); ++i) {
      //       if (!prim[i] && !prim[i + 2]) ops.push_back(i);
      // }
      // int have = ops.size();
 
      int t; cin >> t;
      while (t--) {
            // int n, m; cin >> n >> m;
            // vector <int> aa;
            // pair <int, int> tina = {0, 0};
            // pair <int, int> rahul = {n - 1, m - 1};
            // auto dist = [&](pair <int, int> a, pair <int, int> b) {
            //       return abs(a.first - b.first) + abs(a.second - b.second);
            // };
            // for (int k = n * m - 1; k >= 0; --k) {
 
            // }     
            int n; cin >> n;
            for (int i = 0; i <= n; ++i) g[i].clear();
            ss.clear();
            bool ok = true;
            vector <pair <int, int>> dd;
            for (int i = 0; i < n - 1; ++i) {
                  int u, v; cin >> u >> v;
                  g[u].push_back(v);
                  g[v].push_back(u);
                  dd.push_back({u, v});
            }
            for (int i = 1; i <= n; ++i) {
                  if (g[i].size() >= 3) {
                        ok = false;
                  }
            }
            if (!ok) {
                  cout << "-1\n";
                  continue;
            }
            ed = -1;
            dfs1(1, -1);
            dfs(ed, -1, 2);
            for (auto p : dd) cout << ss[p] << ' ';
            cout << '\n';
      }
}