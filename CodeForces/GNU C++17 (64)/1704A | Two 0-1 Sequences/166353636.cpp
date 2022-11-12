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
            int n, m; cin >> n >> m;
            string a, b; cin >> a >> b;;
            bool ok = true;
            for (int i = 0; i < m - 1; ++i) {
                  ok &= a[n - 1 - i] == b[m - 1 - i]; 
            }
            if (ok) {
                  int c0 = 0, c1 = 0;
                  for (int i = 0; i <= n - m; ++i) {
                        c0 += a[i] == '0';
                        c1 += a[i] == '1';
                  }
                  if (b[0] == '0' && c0) cout << "YES\n";
                  else if (b[0] == '1' && c1) cout << "YES\n";
                  else cout << "NO\n";
            } else cout << "NO\n";
      }
}