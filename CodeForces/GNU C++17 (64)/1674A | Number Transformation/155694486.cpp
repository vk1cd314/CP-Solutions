#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
using namespace std;
 
int main() {
      // ios_base::sync_with_stdio(0);
      // cin.tie(0);
 
      int t; cin >> t;
      outer: while (t--) {
            int64_t x, y; cin >> x >> y;
            if (x == y) cout << "1 1\n";
            else if (y < x || (y % x)) cout << "0 0\n";
            else {
                  int64_t p = y / x;
                  for (int i = 2; i <= 100; ++i) {
                        int64_t po = 1;
                        for (int j = 0; j <= 100; ++j) {
                              if (po > 100) break;
                              if (po == p) {
                                    cout << j << ' ' << i << '\n';
                                    goto outer; 
                              }
                              po *= i;
                        }
                  }
                  debug(3);
                  cout << "0 0\n";
            }
      }
}