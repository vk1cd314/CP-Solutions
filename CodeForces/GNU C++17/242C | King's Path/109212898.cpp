#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
using namespace std;
 
int main() {
      #ifdef Icry
            auto begin = std::chrono::high_resolution_clock::now();
      #endif
      ios_base :: sync_with_stdio(0);
      cin.tie(0);
 
      pair <int, int> st, ed; cin >> st.first >> st.second >> ed.first >> ed.second;
      map <pair <int, int>, int> dist;
      map <pair <int, int>, int> have;
      int n; cin >> n;
      for (int i = 0; i < n; ++i) {
            int r, x, y; cin >> r >> x >> y;
            for (int j = x; j <= y; ++j) have[{r, j}]++;
      }
      
      int ans = -1;
      int dx[] = {1, 0, -1, 1, -1, 1, 0, -1};
      int dy[] = {1, 1, 1, 0, 0, -1, -1, -1};
      queue <pair <int, int>> q;
      q.push(st);
      dist[st] = 0;
      while (!q.empty()) {
            auto u = q.front(); q.pop();
            for (int i = 0; i < 8; ++i) {
                  pair <int, int> pp = {u.first + dx[i], u.second + dy[i]};
                  if (have[pp] == 0) continue;
                  if (dist[pp]) continue;
                  dist[pp] = dist[u] + 1;
                  q.push(pp);
                  if (pp == ed) ans = dist[pp];
            }
      }
 
      cout << ans << '\n';
 
      #ifdef Icry
            auto end = std::chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << std::chrono::duration_cast <std::chrono::duration <double>>(end - begin).count() << " seconds]\n";  
      #endif
}