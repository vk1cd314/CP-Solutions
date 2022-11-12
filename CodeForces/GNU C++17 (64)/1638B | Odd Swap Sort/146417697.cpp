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
            vector <int64_t> b, c;
            for (int i = 0; i < n; ++i) {
                  if (a[i] % 2) b.push_back(a[i]);
                  else c.push_back(a[i]); 
            }
            if (is_sorted(b.begin(), b.end()) && is_sorted(c.begin(), c.end())) cout << "YES\n";
            else cout << "NO\n";
      }
}