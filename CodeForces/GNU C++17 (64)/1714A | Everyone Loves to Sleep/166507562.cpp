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
            int n, h, m; cin >> n >> h >> m;
            int ans = 0;
            set <pair <int, int>> ss;
            for (int i = 0; i < n; ++i) {
                  int a, b; cin >> a >> b;
                  ss.insert({a, b});
            }
            while (!ss.count({h, m})) {
                  ++ans;
                  m++;
                  if (m == 60) m = 0, h++;
                  if (h == 24) h = 0;
            }
            cout << ans / 60 << ' ' << ans % 60 << '\n';
      }
}