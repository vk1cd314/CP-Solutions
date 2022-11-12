#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif

using namespace std;

const int MOD = 998244353;

int main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);

      int64_t n, ans = 0; cin >> n;
      for (int64_t a = 1; a * a <= n; ++a) {
            int64_t b = min(n / a, (int64_t) 2LL * n - a);
            if (a % 2 == 0) (ans += b / 2 - (a - 1) / 2) %= MOD;
            else (ans += (b + 1) / 2 - a / 2) %= MOD;
      }
      cout << ans << '\n';
}