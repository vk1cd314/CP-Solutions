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
            vector <int64_t> a(n); for (auto &x : a) cin >> x;
            if (n % 2 == 0) {
                  cout << "YES\n";
                  continue;
            } else {
                  bool ok = false;
                  for (int i = 0; i + 1 < n; ++i) {
                        if (a[i] >= a[i + 1]) ok = true;
                  }
                  cout << (ok ? "YES\n" : "NO\n");
            }
      }
}