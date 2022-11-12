#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
using namespace std;
 
int main() {
      // ios_base::sync_with_stdio(0);
      // cin.tie(0);
 
      int t; cin >> t;
      outer: while (t--) {
            int n; cin >> n;
            char c; cin >> c;
            string s; cin >> s;
            int ct = 0;
            for (int i = 0; i < n; ++i) {
                  if (s[i] != c) ct++;
            }
            if (!ct) {
                  cout << "0\n";
                  continue;
            }
            for (int i = 1; i <= n; ++i) {
                  bool ok = true;
                  for (int j = i; j <= n; j += i) {
                        if (s[j - 1] != c) {
                              ok = false;
                              break;
                        }
                  }
                  if (ok) {
                        cout << "1\n" << i << '\n';
                        goto outer;
                  }
            }
            cout << 2 << '\n' << n << ' ' << n - 1 << '\n';
      }
}