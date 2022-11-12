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

      int n; cin >> n;
      vector <int64_t> a(n); for (auto& x : a) cin >> x;
      int64_t inn = 0;
      for (int i = 0; i < n; ++i) {
            int64_t x; cin >> x;
            inn += x * a[i];
      }

      cout << (!inn ? "Yes\n" : "No\n");
}
