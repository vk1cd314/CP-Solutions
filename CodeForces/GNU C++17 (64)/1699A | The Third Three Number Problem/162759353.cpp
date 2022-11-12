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
            int n; cin >> n;
            if (n % 2 == 0) cout << n / 2 << ' ' << n / 2 << ' ' << 0 << '\n';
            else cout << "-1\n";
      }
}