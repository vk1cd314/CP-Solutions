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
            long long a, b, c, x, y; cin >> a >> b >> c >> x >> y;
            x = max(0ll, x - a);
            y = max(0ll, y - b);
            if (x + y <= c) cout << "YES\n";
            else cout << "NO\n";
      }
}