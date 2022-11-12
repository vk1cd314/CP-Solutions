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
            string s; cin >> s;
            // f(t) = f(w)
            int idx = s.find('0');
            debug(idx);
            if (idx == -1) {
                  // all 1s ez
                  cout << "1 " << n / 2 << ' ' << n / 2 + 1 << ' ' << n / 2 + n / 2 << '\n';
            } else if (idx < n / 2) {
                  // 0thing thing f(t) = f(w)
                  cout << idx + 1 << ' ' << n << ' ' << idx + 2 << ' ' << n << '\n';
            } else {
                  // thing0 thing
                  // f(t) = f(w) * 2
                  cout << "1 " << idx + 1 << " 1 " << idx << '\n';
            }
      }
}