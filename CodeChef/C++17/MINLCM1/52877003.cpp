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
            int64_t x, k; cin >> x >> k;

            cout << x * 2LL << ' ' << (x * k - 1) * x * k << '\n';
      }
}