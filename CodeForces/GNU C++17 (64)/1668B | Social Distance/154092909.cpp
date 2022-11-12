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
            int64_t n, m; cin >> n >> m;
            vector <int64_t> a(n);
            for (int i = 0; i < n; ++i) {
                  cin >> a[i];
            }
            sort(a.rbegin(), a.rend());
            bool ok = true;
            for (int i = 0; i < n - 1; ++i) {
                  m -= a[i] + 1;
                  if (m < 0) {
                        ok = false;
                        break;
                  }
            }
            m -= 1;
            if (m < a[0]) ok = false;
            cout << (ok ? "YES\n" : "NO\n"); 
      }
}