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
            int64_t l, r; cin >> l >> r;
            int64_t a = r, b = max(l, r / 2 + 1);
            cout << a % b << '\n';
      }
}