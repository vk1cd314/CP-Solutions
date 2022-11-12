#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif

using namespace std;

const int N = 2e5 + 10;
const int mod = 1e9 + 7;
vector <int> g[N];
int dist[N];
bool vis[N];
int dp[N];

int main() {
      #ifdef Icry
            auto begin = chrono::high_resolution_clock::now();
      #endif
      ios_base::sync_with_stdio(0);
      cin.tie(0);

      int n, m; cin >> n >> m;
      while (m--) {
            int u, v; cin >> u >> v;
            --u, --v;
            g[u].push_back(v);
            g[v].push_back(u);
      }

      memset(dist, 0x3f3f3f3f, sizeof dist);
      memset(vis, false, sizeof vis);
      memset(dp, 0, sizeof dp);

      dist[0] = 0;
      dp[0] = 1;
      queue <int> q;
      q.push(0);

      while (!q.empty()) {
            int u = q.front(); q.pop();
            if (vis[u]) continue;
            vis[u] = true;
            for (int v : g[u]) {
                  if (!vis[v]) q.push(v);
                  if (dist[u] + 1 < dist[v]) {
                        dist[v] = dist[u] + 1; 
                        dp[v] = dp[u];
                  } else if (dist[u] + 1 == dist[v]) {
                        dp[v] = (dp[v] + dp[u]) % mod;
                  }
            }
      }

      cout << dp[n - 1] << '\n';


      #ifdef Icry
            auto end = chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << chrono::duration_cast <chrono :: duration <double>> (end - begin).count() << " seconds]\n";  
      #endif
}