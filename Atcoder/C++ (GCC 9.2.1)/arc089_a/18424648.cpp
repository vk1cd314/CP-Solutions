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

      int n; cin >> n;
      int t_now = 0, x_now = 0, y_now = 0;
      bool ok = true;
      for (int i = 0; i < n; ++i) {
            int t, x, y; cin >> t >> x >> y;
            int diff = abs(x - x_now) + abs(y - y_now);
            int t_diff = t - t_now;
            if (diff > t_diff) ok = false;
            else if ((t_diff - diff) % 2) ok = false;
            x_now = x, y_now = y;
            t_now = t;
      } 
      
      cout << (ok ? "Yes" : "No");
}
