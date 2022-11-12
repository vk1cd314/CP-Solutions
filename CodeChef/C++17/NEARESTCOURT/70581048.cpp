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
            int z = x + y >> 1;
            cout << max(abs(x - z), abs(y - z)) << '\n';
      }
}