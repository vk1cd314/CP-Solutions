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
            vector <int> s(n); for (int &x : s) cin >> x;
            string v; cin >> v;
            int mn = INT_MAX;
            for (int i = 0; i < n; ++i) if (v[i] == '0') mn = min(mn, s[i]);
            cout << mn << '\n';
      }
}