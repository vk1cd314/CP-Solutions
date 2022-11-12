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
            string s; cin >> s;
            map <long long, long long> cnt;
            int ss = 0;
            for (int i = 0; i < n; ++i) {
                  ss += (s[i] == '1');
                  cnt[2ll * ss]++;
            }
            long long tot = ss;
            long long ans = 0;
            debug(cnt);
            for (int i = 0; i < m; ++i) {
                  int x = i, y = m - i - 1;
                  debug(x, y);
                  ans += cnt[tot * (y - x + 1)];
                  debug(cnt[tot * (y - x + 1)]);
            }
            cout << ans << '\n';
      }
} 
// tot * c1 + x == tot - x + tot * c2
// 2 * x == tot * (c2 - c1 + 1)
// 0000