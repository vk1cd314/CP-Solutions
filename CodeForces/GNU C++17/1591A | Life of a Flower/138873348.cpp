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
            int ans = 1;
            for (int i = 0; i < n; ++i) {
                  if (i > 0 && a[i] == 0 && a[i - 1] == 0) {
                        ans = -1;
                        break;
                  } else {
                        if (a[i] == 1) ans++;
                        if (i > 0 && a[i] == 1 && a[i - 1] == 1) ans--, ans += 5;
                  }
            }
            cout << ans << '\n';
      }
}