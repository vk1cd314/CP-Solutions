#include <bits/stdc++.h>

using namespace std;

#ifdef BOI
#include "debug.h"
#else
#define debug(args...)
#endif

typedef long double ld;

int main() {
      ios_base :: sync_with_stdio(0);
      cin.tie(0);

      ld sx, sy, gx, gy;
      cin >> sx >> sy >> gx >> gy;

      ld x = (sy * gx + gy * sx) / (sy + gy);

      cout << fixed << setprecision(10) << x;
}
