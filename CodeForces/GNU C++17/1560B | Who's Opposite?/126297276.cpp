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
            int64_t a, b, c; cin >> a >> b >> c;
            int64_t sz = 2 * abs(a - b);
            int64_t e = (c + abs(a - b)) % sz;
            if (!e) e = sz;
 
            if (a > sz || b > sz || c > sz) cout << "-1\n";
            else if (e == a || e == b) cout << "-1\n";
            else {
                  int64_t f = (c - abs(a - b)) % sz;
                  f += sz;
                  f %= sz;
                  if (!f) f = sz;
                  debug(a, b, c, e, f);
                  if (f != e) cout << "-1\n";
                  else {
                        if (f == c) cout << "-1\n";
                        else cout << e << '\n';
                  }
            }
      }
}