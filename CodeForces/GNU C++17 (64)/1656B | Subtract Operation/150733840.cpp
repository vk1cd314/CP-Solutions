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
            int n;
            int64_t k;
            cin >> n >> k;
            vector <int64_t> a(n); for (auto &x : a) cin >> x;
 
            sort(a.begin(), a.end());
            bool ok = false;
            for (int i = 0; i < n; ++i) {
                  auto it = lower_bound(a.begin(), a.end(), k + a[i]);
                  if (it != a.end() && *it == k + a[i]) ok = true;
            } 
            cout << (ok ? "YES\n" : "NO\n");
      }
}