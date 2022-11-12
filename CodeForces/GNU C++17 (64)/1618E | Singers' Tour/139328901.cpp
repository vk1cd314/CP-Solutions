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
      outer: while (t--) {
            int n; cin >> n;
            vector <int64_t> b(n), a(n);
            int64_t s = 0;
            for (auto &x : b) cin >> x, s += x;
            if (s % (n * (n + 1) / 2)) {
                  cout << "NO\n";
                  continue;
            } 
            s /= n * (n + 1) / 2;
            for (int i = 0; i < n; ++i) {
                  int64_t tot = b[i > 0 ? i - 1 : n - 1] - (b[i] - s);
                  if (tot <= 0 || tot % n) {
                        cout << "NO\n";
                        goto outer;
                  }
                  a[i] = tot / n;
            }
            cout << "YES\n";
            for (int x : a) cout << x << ' ';
            cout << '\n';
      }
}