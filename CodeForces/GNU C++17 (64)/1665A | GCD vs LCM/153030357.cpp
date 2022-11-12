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
            int64_t n; cin >> n;
            int64_t c = 1 , d = 1;
            int64_t a = 1, b = n - 3;
            cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
      }
}