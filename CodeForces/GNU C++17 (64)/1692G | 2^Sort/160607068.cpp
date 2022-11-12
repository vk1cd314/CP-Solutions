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
            int n, k; cin >> n >> k;
            vector <long long> a(n); for (auto &x : a) cin >> x;
            int ct = 0;
            int ans = 0;
            for (int i = 0; i + 1 < n; ++i) {
                  if (a[i] < 2LL * a[i + 1]) ct++;
                  else {
                        // debug(ct, i);
                        ans += max(0, ct - k + 1);
                        ct = 0;
                  }
            }
            // debug(ct);
            ans += max(0, ct - k + 1);
            cout << ans << '\n';
      }
 
}
// k + 1 length subarrays with a[i] < 2 * a[i + 1]    