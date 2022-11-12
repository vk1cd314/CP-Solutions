#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
using namespace std;
 
#define ll long long
 
int main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
 
      int t; cin >> t;
      outer: while (t--) {
            ll a, b, c, d; cin >> a >> b >> c >> d;
            for (ll x = a + 1; x <= c; ++x) {
                  ll prod = a * b;
                  ll gg = __gcd(x, prod);
                  ll ff = d * gg / prod;
                  ff *= x / gg;
                  ll y = ff * prod / x;
                  if (y > b && y <= d && (x * y) % (a * b) == 0) {
                        cout << x << ' ' << y << '\n';
                        goto outer;
                  }
            }
            cout << "-1 -1\n";
      }
}