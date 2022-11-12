#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif

using namespace std;

const int N = 1e5 + 6 + 9;
vector <int> g[N];
int F[N];

int rec(int u) {
      int &ret = F[u];
      if (~ret) return ret;

      ret = 0;
      for (int v : g[u]) {
            ret = max(ret, rec(v) + 1);
      }

      return ret;
}

int main() {
      #ifdef Icry
            auto begin = std::chrono::high_resolution_clock::now();
      #endif
      ios_base :: sync_with_stdio(0);
      cin.tie(0);

      int n, m; cin >> n >> m;
      memset(F, -1, sizeof F);
      for (int i = 0; i < m; ++i) {
            int x, y; cin >> x >> y; --x, --y;
            g[x].push_back(y);
      }

      int ans = 0;
      for (int i = 0; i < n; ++i) {
            ans = max(ans, rec(i));
      }

      cout << ans << '\n';

      #ifdef Icry
            auto end = std::chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << std::chrono::duration_cast <std::chrono::duration <double>>(end - begin).count() << " seconds]\n";  
      #endif
}