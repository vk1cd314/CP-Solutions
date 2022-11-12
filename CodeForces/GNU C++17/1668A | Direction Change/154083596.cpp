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
            int64_t n, m; cin >> n >> m;
            if (n > m) swap(n, m);
            if (n == 1) {
                  if (m == 1) {
                        cout << "0\n";
                  }
                  else if (m == 2) {
                        cout << "1\n";
                  } else cout << "-1\n";
                  continue;
            } 
            int64_t mn = m - n;
            int64_t ext = mn + 2LL * (mn / 2LL);
            cout << 2LL * (n - 1) + ext << '\n';
      }
}