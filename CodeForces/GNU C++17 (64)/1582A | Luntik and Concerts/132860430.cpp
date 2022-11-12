#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
using namespace std;
 
int main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
 
      int t; cin >> t;
      while (t--) {
            int64_t a, b, c; cin >> a >> b >> c;
 
            int64_t ans = LLONG_MAX;            
            for (int64_t i = max((int64_t) 0, a / 2 - 6); i <= min(a, a / 2 + 6); ++i) {
                  for (int64_t j = max((int64_t) 0, b / 2 - 6); j <= min(b, b / 2 + 6); ++j) {
                        for (int64_t k = max((int64_t) 0, c / 2 - 6); k <= min(c, c / 2 + 6); ++k) {
                              ans = min(ans,(int64_t) abs(i + 2LL * j + 3LL * k - (a + 2LL * b +  3LL * c - (i + 2LL * j + 3LL * k))));
                        }
                  }
            }
 
            cout << ans << '\n';
      }
}