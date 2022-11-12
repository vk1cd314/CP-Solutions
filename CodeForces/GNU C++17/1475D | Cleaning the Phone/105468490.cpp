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
            int64_t n, m; cin >> n >> m;
 
            vector <int64_t> a(n), one, two, oneP, twoP;
            for (auto& x : a) cin >> x;
 
            oneP.push_back(0);
            twoP.push_back(0);
            for (int i = 0, x; i < n; ++i) {
                  cin >> x;
                  if (x == 1) one.push_back(a[i]);
                  else two.push_back(a[i]);
            }
            sort(one.rbegin(), one.rend());
            sort(two.rbegin(), two.rend());
 
            for (auto x : one) oneP.push_back(oneP.back() + x);
            for (auto x : two) twoP.push_back(twoP.back() + x);
 
            // debug(a, one, two, oneP);
            // debug(3);
            // debug("sss");
            int64_t ans = INT_MAX;
            for (int i = 0; i < (int) oneP.size(); ++i) {
                  int64_t rem = m - oneP[i];
                  if (twoP.back() < rem) continue;
                  int x = lower_bound(twoP.begin(), twoP.end(), rem) - twoP.begin();
                  ans = min(ans, (int64_t) i + (x << 1));
            }
 
            if (ans == INT_MAX) ans = -1;
            cout << ans << '\n';
      }
 
      #ifdef SENDHELP
            auto end = std::chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << std::chrono::duration_cast <std::chrono::duration <double>>(end - begin).count() << " seconds]\n";  
      #endif
}