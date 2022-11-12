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
            vector <int> a(n); for (int &x : a) cin >> x;
            sort(a.begin(), a.end());
            if (a[0] == a.back()) {
                  cout << "-1\n";
                  continue;
            }
            int mn = a[0];
            for (int &x : a) x += -mn;
            int ans = 0;
            for (int i = 0; i < n; ++i) {
                  ans = __gcd(ans, a[i]);
            }
            debug(a);
            cout << ans << '\n';
      }
}