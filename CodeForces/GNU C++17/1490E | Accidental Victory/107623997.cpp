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
 
      int t; cin >> t;
      while (t--) {
            int n, cnt = 1; cin >> n;
            vector <pair <int64_t, int>> a(n); for (auto &pp : a) cin >> pp.first, pp.second = cnt++;
            sort(a.begin(), a.end());
 
            int64_t curr = 0, mx = -33;
            for (int i = 0; i < n; ++i) {
                  curr += a[i].first;
                  if (i + 1 < n && a[i + 1].first > curr) mx = a[i + 1].first;
            }
 
            vector <int> ans;
            for (auto [x, y] : a) if (x >= mx) ans.push_back(y);
 
            sort(ans.begin(), ans.end());
            cout << ans.size() << '\n';
            for (int x : ans) cout << x << ' ';
            cout << '\n';
      }
 
      #ifdef SENDHELP
            auto end = std::chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << std::chrono::duration_cast <std::chrono::duration <double>>(end - begin).count() << " seconds]\n";  
      #endif
}