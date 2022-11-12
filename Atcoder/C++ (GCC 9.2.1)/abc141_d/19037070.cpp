#include <bits/stdc++.h>

using namespace std;

#ifdef BOI
#include "debug.h"
#else
#define debug(args...)
#endif

int main() {
      ios_base :: sync_with_stdio(0);
      cin.tie(0);

      int n, m; cin >> n >> m;
      multiset <int> s;
      for (int i = 0, x; i < n; ++i) cin >> x, s.insert(x);

      while (m--) {
            int now = *s.rbegin();
            s.erase(--s.end());
            s.insert(now / 2);
      }

      long long ans = 0;
      for (auto x : s) ans += 1LL * x;

      cout << ans << '\n';
}
