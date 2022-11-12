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

      int64_t x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
      int64_t d = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
      debug(d);
      if (d > 20) cout << "No\n";
      else {
            int64_t num = 20 - d, denum = d;
            num /= __gcd(d, 20 - d);
            denum /= __gcd(d, 20 - d);
            int64_t sqrnum = sqrt(num), sqrdenum = sqrt(denum);
            if (sqrnum * sqrnum != num || sqrdenum * sqrdenum != denum) cout << "No\n";
            else {
                  // debug(x1 + x2 + sqr * y2 - sqr * y1);
                  // debug(y1 + y2 + sqr * x2 - sqr * x1);
                  if ((x1 * sqrdenum + x2 * sqrdenum + sqrnum * y2 - sqrnum * y1) % (2LL * sqrdenum)) cout << "No\n";
                  else if ((y1 * sqrdenum + y2 * sqrdenum + sqrnum * x2 - sqrnum * x1) % (2LL * sqrdenum)) cout << "No\n";
                  else cout << "Yes\n";
            }
      }

}