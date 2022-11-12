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
            int i1 = max_element(a.begin(), a.end()) - a.begin();
            int i2 = min_element(a.begin(), a.end()) - a.begin();
            cout << i1 + 1 << ' ' << i2 + 1  << '\n';
      }
}