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
            vector <int> p(n); for (int &x : p) cin >> x;
            vector <int> pp(n);
            iota(pp.begin(), pp.end(), 1);
            for (int i = 0; i < n; ++i) {
                  if (pp[i] == p[i]) continue;
                  else {
                        int mn = (int)(min_element(p.begin() + i, p.end()) - p.begin());
                        debug(p, mn);
                        reverse(p.begin() + i, p.begin() + mn + 1);
                        break;
                  }
            }
            for (int x : p) cout << x << ' ';
            cout << '\n';
      }
}