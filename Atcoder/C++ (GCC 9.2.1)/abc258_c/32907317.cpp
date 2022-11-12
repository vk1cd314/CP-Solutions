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

      int n, q; cin >> n >> q;
      string s; cin >> s;
      int st = 0;
      while (q--) {
            int type; cin >> type;
            if (type == 1) {
                  int x; cin >> x;
                  st = (st + n - x) % n;
            } else {
                  int x; cin >> x;
                  --x;
                  debug(st, x);
                  cout << s[(st + x) % n] << '\n';
            }
      }
}
// abcde - 0 
// deabc - 3
// cdeab - 2