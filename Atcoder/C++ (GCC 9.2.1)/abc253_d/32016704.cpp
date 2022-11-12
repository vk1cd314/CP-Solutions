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

      long long n, a, b; cin >> n >> a >> b;
      
      auto sum = [&](long long x) {
            return (x * (x + 1)) / 2ll;
      };

      long long gg = lcm(a, b);
      debug(sum(n));
      debug(sum(n / a) * a);
      debug(sum(n / b) * b);
      debug(sum(n / gg) * gg);

      long long ans = sum(n) - sum(n / a) * a - sum(n / b) * b + sum(n / gg) * gg;
      // a + 2a + 3a + 4a + n / a  * a
      cout << ans << '\n';
}