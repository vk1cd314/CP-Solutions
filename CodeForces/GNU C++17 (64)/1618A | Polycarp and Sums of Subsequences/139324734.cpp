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
            vector <int64_t> b(7);
            for (auto &x : b) cin >> x;
 
            cout << b[0] << ' ' << b[1] << ' ' << b[6] - b[1] - b[0] << '\n';
      }
}