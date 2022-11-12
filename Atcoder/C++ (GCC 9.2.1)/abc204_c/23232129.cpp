#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif

using namespace std;

const int N = 2e3 + 20;
vector <int> g[N];
bool vis[N];
int64_t cnt = 0;

void dfs(int u) {
      vis[u] = true;
      cnt++;
      for (int v : g[u]) {
            if (!vis[v]) dfs(v);
      }
}     

int main() {
      #ifdef Icry
            auto begin = chrono :: high_resolution_clock :: now();
      #endif
      ios_base :: sync_with_stdio(0);
      cin.tie(0);

      int n, m; cin >> n >> m;

      for (int i = 0; i < m; ++i) {
            int a, b; cin >> a >> b;
            --a, --b;
            g[a].push_back(b);
      }

      // memset(dp, -1, sizeof dp);
      int64_t ans = 0;
      for (int i = 0; i < n; ++i) {
            memset(vis, false, sizeof vis);
            // if (!vis[i]) {
                  cnt = 0, dfs(i), ans += cnt;
            // }
      } 

      cout << ans << '\n';

      #ifdef Icry
            auto end = chrono :: high_resolution_clock :: now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << chrono :: duration_cast <chrono :: duration <double>> (end - begin).count() << " seconds]\n";  
      #endif
}