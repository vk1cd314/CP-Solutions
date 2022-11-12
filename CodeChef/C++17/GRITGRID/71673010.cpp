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
            int n, m, x, y; cin >> n >> m >> x >> y;
            if ((x + y) % 2 == 0) {
                  if ((n + m) % 2 == 0 && x % 2 == 1) cout << "No\n";
                  else if ((n + m) % 2 == 1 && x % 2 == 0) cout << "No\n";
                  else cout << "Yes\n";
            }
            else cout << "Yes\n";
      }
}