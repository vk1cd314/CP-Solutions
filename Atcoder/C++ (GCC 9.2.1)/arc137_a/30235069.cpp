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

      int64_t l, r; cin >> l >> r;
      int64_t ans = -1;
      for (int64_t i = l; i <= min(r, l + 2000); ++i) {
            for (int64_t j = max(l, r - 2000); j <= r; ++j) {
                  if (i == j) continue;
                  if (__gcd(i, j) == 1) ans = max(ans, j - i);
            }
      }
      cout << ans << '\n';
}