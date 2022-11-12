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
            int64_t n, k; cin >> n >> k;
            cout << ((2LL * n - k - 1LL) / 2) * 2 << '\n';
      }
}