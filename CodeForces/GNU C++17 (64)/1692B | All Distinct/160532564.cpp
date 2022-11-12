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
            set <int> s(a.begin(), a.end());
            int f = (int) a.size() - (int) s.size();
            int ans = s.size();
            if (f & 1) ans--;
            cout << ans << '\n';
      }
}