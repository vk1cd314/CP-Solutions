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
            vector <int64_t> a(n); 
            int64_t g1 = 0, g2 = 0;
            for (auto &x : a) cin >> x;
            for (int i = 0; i < n; ++i) {
                  if (i & 1) g1 = __gcd(g1, a[i]);
                  else g2 = __gcd(g2, a[i]);
            }
 
            debug(g1, g2);
            bool ok1 = true, ok2 = true;
            for (int i = 0; i < n; i += 2) {
                  if (a[i] % g1 == 0) ok1 = false;
            }
            for (int i = 1; i < n; i += 2) {
                  if (a[i] % g2 == 0) ok2 = false;
            }
            
            if (!ok1 && !ok2) cout << 0 << '\n';
            else if (ok1) cout << g1 << '\n';
            else cout << g2 << '\n';
      }
}