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

      string s; cin >> s;
      int n = s.size(), ans = INT_MAX;
      for (int i = 1; i < (1 << n); ++i) {
            int sum = 0;
            for (int j = 0; j < n; ++j) {
                  if (i & (1 << j)) sum += s[j] - '0';
            }

            if (sum % 3 == 0) {
                  ans = min(ans, n - __builtin_popcount(i));
                  // break;
            }
      }

      if (ans == INT_MAX) cout << "-1";
      else cout << ans << endl;
}
