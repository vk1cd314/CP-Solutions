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
            bool ok = true;
            for (int i = 1; i < n; ++i) {
                  if (a[i] % a[0] != 0) ok = false;
            }
            cout << (ok ? "YES\n" : "NO\n");
      }
}