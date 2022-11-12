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
            int64_t a, b; cin >> a >> b;
            if (a > b) swap(a, b);
            int64_t left = b - a;
            cout << min({(int64_t)((left + 2LL * a) / 4LL), a, b}) << '\n';
      }
}