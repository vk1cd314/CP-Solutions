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

      int a, b; cin >> a >> b;
      bool ok = false;
      int x, y;
      for (int i = -100; i <= 100; ++i) {
            for (int j = -100; j <= 100; ++j) {
                  if (i + j == a && i - j == b) {
                        x = i, y = j;
                        ok = true;
                        break;
                  }
            }
            if (ok) break;
      }      

      cout << x << ' ' << y;
}
