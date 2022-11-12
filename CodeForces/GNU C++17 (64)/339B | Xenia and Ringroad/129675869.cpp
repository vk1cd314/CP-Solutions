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
 
      int n, m; cin >> n >> m;
      int64_t curr = 1, ans = 0;
      for (int i = 0; i < m; ++i) {
            int x; cin >> x;
            if (x >= curr) ans += x - curr;
            else ans += n - curr + x;
            curr = x; 
      }
      cout << ans << '\n';
}