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
            vector <int> wr;
            vector <int> p(n + 1);
            for (int i = 0; i < n; ++i) {
                  p[a[i]] = i + 1;
            }
            int gg = 0;
            for (int i = 1; i <= n; ++i) {
                  gg = __gcd(gg, abs(p[i] - i));
            }
            cout << gg << '\n';
      }
}