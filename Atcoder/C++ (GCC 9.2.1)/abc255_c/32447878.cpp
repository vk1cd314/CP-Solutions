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

      long long x, a, d, n; cin >> x >> a >> d >> n;

      if (d < 0) a = a + (n - 1) * d, d = -d;

      long long l = 0, r = n;
      while (r - l > 10) {
            long long m = l + r >> 1;
            if (a + m * d > x) r = m;
            else l = m; 
      }

      long long ans = LLONG_MAX;
      for (long long i = l; i <= min(n - 1, r); ++i) {
            ans = min(ans, abs(a + i * d - x));
      }
      cout << ans << '\n';
}