#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif

using namespace std;

const int64_t mod = 998244353;

int64_t binpow(int64_t a, int64_t n, int64_t m = mod) {
      if (n == 0) return 1LL;
      int64_t res = binpow(a, n >> 1LL) % m;
      return (((res * res) % m) * (n & 1 ? a : 1LL)) % m;
}

int main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);

      // f(x) = x - 10^(floor(log10(x))) + 1
      // 0 - b + 1
      // 1 - b + 1 
      // 2 - b + 1
      // 3 - b + 1
      // ...
      // 9 - b + 1
      // 10 - c + 1
      int64_t n; cin >> n;
      int64_t p10 = 1;
      int64_t ans = 0;
      for (int64_t i = 0; i <= 18; ++i) {
            debug(p10);
            if (10LL * p10 > n) {
                  int64_t xx = n - p10 + 1;
                  // int64_t tot = xx % mod;
                  xx %= mod;
                  xx = (xx * (xx + 1)) % mod;
                  xx *= binpow(2, mod - 2);
                  xx %= mod;
                  // xx = (xx - p10 * tot % mod) % mod;
                  // xx = (xx + mod) % mod;
                  // xx = (xx + tot) % mod;
                  ans = (ans + xx) % mod;
                  debug(xx);
                  debug(ans);
                  break;
            }
            int64_t xx = 10LL * p10 - p10;
            // int64_t tot = xx % mod;
            xx %= mod;
            xx = (xx * (xx + 1)) % mod;
            xx *= binpow(2, mod - 2);
            xx %= mod;
            // xx = (xx - p10 * tot % mod) % mod;
            // xx = (xx + mod) % mod;
            // xx = (xx + tot) % mod;
            ans = (ans + xx) % mod;
            debug(xx);
            p10 *= 10LL;
            debug(ans);
      }
      cout << ans << '\n';
      //ami retard
}