#include <bits/stdc++.h>

using namespace std;

#ifdef BOI
#include "debug.h"
#else
#define debug(args...)
#endif

int main() {
      ios_base :: sync_with_stdio(0);
      cin.tie(0);

      int a, b, x, y; cin >> a >> b >> x >> y;

      if (a == b) {
            cout << x << endl;
      } else if (a > b) {
            int ans = min({(a - b) * y + x, (2 * (a - b) - 1) * x, x + (a - 1 - b) * y});
            cout << ans << endl;     
      } else if (a < b) {
            int ans = min((b - a) * y + x, (2 * (b - a) + 1) * x);
            cout << ans << endl;
      }
}
