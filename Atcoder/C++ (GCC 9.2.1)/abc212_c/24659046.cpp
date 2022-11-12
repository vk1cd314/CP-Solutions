#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif

using namespace std;

int main() {
      #ifdef Icry
            auto begin = chrono::high_resolution_clock::now();
      #endif
      ios_base::sync_with_stdio(0);
      cin.tie(0);

      int n, m; cin >> n >> m;
      vector <pair <int, int>> aa;
      for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            aa.push_back({x, 1});
      }

      for (int i = 0; i < m; ++i) {
            int x; cin >> x;
            aa.push_back({x, 2});
      }

      sort(aa.begin(), aa.end());

      int ans = INT_MAX;
      for (int i = 0; i + 1 < n + m; ++i) {
            if (aa[i].second != aa[i + 1].second) {
                  ans = min(ans, abs(aa[i].first - aa[i + 1].first));
            }
      }

      cout << ans << '\n';

      #ifdef Icry
            auto end = chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << chrono::duration_cast <chrono :: duration <double>> (end - begin).count() << " seconds]\n";  
      #endif
}