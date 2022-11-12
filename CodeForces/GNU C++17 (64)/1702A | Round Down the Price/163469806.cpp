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
 
      long long p10[12];
      p10[0] = 1;
      for (int i = 1; i < 12; ++i) p10[i] = 10ll * p10[i - 1];
 
      int t; cin >> t;
      while (t--) {
            long long m; cin >> m;
            long long ans = LLONG_MAX;
            for (int i = 0; i < 12; ++i) {
                  if (p10[i] <= m) ans = min(ans, m - p10[i]);
            }
            cout << ans << '\n';
      }
}