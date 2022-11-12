#include <bits/stdc++.h>
 
using namespace std;
 
#ifdef SENDHELP
#include "debug.h"
#else
#define debug(args...)
#endif
 
int main() {
      #ifdef SENDHELP
            auto begin = std::chrono::high_resolution_clock::now();
      #endif
      ios_base :: sync_with_stdio(0);
      cin.tie(0);
 
      int m, n; cin >> n >> m;
      string s, t; cin >> s >> t;
      vector <int> mx, mn;
 
      int j = 0;
      for (int i = 0; i < m; ++i) {
            while (j < n && s[j] != t[i]) ++j;
            mn.push_back(j);
            ++j;
      }
      j = n - 1; 
      for (int i = m - 1; i >= 0; --i) {
            while (j >= 0 && s[j] != t[i]) --j;
            mx.push_back(j);
            --j;
      }
 
      debug(mn, mx);
      int ans = 0;
      reverse(mx.begin(), mx.end());
      for (int i = 0; i + 1 < m; ++i) ans = max(ans, mx[i + 1] - mn[i]);
 
      cout << ans << '\n';
 
      #ifdef SENDHELP
            auto end = std::chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << std::chrono::duration_cast <std::chrono::duration <double>>(end - begin).count() << " seconds]\n";  
      #endif
}