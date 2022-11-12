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
            int64_t k = 1;
            while (n % 2 == 0) n >>= 1, k <<= 1;
            if (n == 1) cout << "-1\n";
            else cout << min(n, k << 1) << '\n'; 
      }
}