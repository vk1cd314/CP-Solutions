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
 
      int n, m; cin >> n >> m;
      vector <vector <int>> a(n, vector <int>(m));
      for (auto &x : a) for (auto &y : x) cin >> y;
 
      int64_t l = -1, r = 2e9 + 1;
      pair <int, int> tmp = {-1, -1};
      while (r - l > 1) {
            int64_t mi = l + r >> 1;
            vector <int> mask(1 << m, -69);
            for (int i = 0; i < n; ++i) {
                  int currMask = 0;
                  for (int j = 0; j < m; ++j) {
                        if (a[i][j] >= mi) currMask ^= (1 << j);
                  }
                  mask[currMask] = i;
            }
            bool ok = false;
            for (int i = 0; i < (1 << m) && !ok; ++i) {
                  for (int j = 0; j < (1 << m) && !ok; ++j) {
                        if ((i | j) == (1 << m) - 1 && mask[i] != -69 && mask[j] != -69) {
                              ok = true;
                              tmp = {i, j};
                        }
                  }
            }
            if (ok) l = mi;
            else r = mi;
      }
 
      debug(tmp, l);
      pair <int, int> ans = {-1, -1};
      for (int i = 0; i < n; ++i) {
            int currMask = 0;
            for (int j = 0; j < m; ++j) {
                  if (a[i][j] >= l) currMask ^= (1 << j);
            }
            if (ans.first == -1 && currMask == tmp.first) ans.first = i + 1;
            if (ans.second == -1 && currMask == tmp.second) ans.second = i + 1;
      }
 
      cout << ans.first << ' ' << ans.second << '\n';
 
      #ifdef Icry
            auto end = std::chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << std::chrono::duration_cast <std::chrono::duration <double>>(end - begin).count() << " seconds]\n";  
      #endif
}