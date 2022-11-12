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
            vector <int> a(n), b(n); 
            for (int &x : a) cin >> x;
            for (int &x : b) cin >> x;
            sort(a.begin(), a.end());
            sort(b.begin(), b.end());
            bool ok = true;
            for (int i = 0; i < n && ok; ++i) {
                  ok &= (a[i] == b[i] || a[i] == b[i] - 1);
            }
            cout << (ok ? "YES\n" : "NO\n");
      }
}