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
            int64_t n, k; cin >> n >> k;
            vector <int64_t> a(n); for (auto &x : a) cin >> x;
            vector <int> bit(31, 0);
            for (int i = 0; i < n; ++i) {
                  for (int j = 0; j < 31; ++j) {
                        if (!(a[i] & 1LL << j)) bit[j]++; 
                  }
            }
            // debug(bit);
            for (int i = 30; i >= 0 && k > 0; --i) {
                  if (bit[i] <= k) {
                        for (int j = 0; j < n && k > 0; ++j) {
                              if (!(a[j] & 1LL << i)) {
                                    a[j] |= 1LL << i, --k;
                              }
                        }
                  }
            }
            // debug(a);
            int64_t ans = a[0];
            for (int i = 1; i < n; ++i) ans &= a[i];
            cout << ans << '\n';
 
      }
}