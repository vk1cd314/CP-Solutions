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
            long long n, m; cin >> n >> m;
            long long ans = m * (m - 1) / 2;
            ans += m * n * (n + 1) / 2;
            cout << ans << '\n';
      }
}