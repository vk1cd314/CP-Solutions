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
            int x, y; cin >> x >> y;
            if (y > x) {
                  int f = abs(x - y);
                  cout << (f + 1) / 2 + (f & 1) << '\n';
            } else cout << abs(x - y) << '\n';
      }
}