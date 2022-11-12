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
            int cone = count(a.begin(), a.end(), 1);
            if (cone != 1) cout << "NO\n";
            else {
                  bool ok = false;
                  for (int i = 0; i < n; ++i) {
                        ok |= a[(i + 1) % n] - a[i] > 1;
                  }
                  cout << (ok ? "NO\n" : "YES\n");
            }
      }
}