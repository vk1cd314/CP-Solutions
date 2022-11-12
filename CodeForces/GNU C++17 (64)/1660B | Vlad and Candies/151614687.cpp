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
            if (n == 1) cout << (a[0] == 1 ? "YES\n" : "NO\n");
            else cout << (a.back() - a[n - 2] > 1 ? "NO\n" : "YES\n");
      }
}