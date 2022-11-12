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
 
      int n; cin >> n;
      vector <int64_t> a(n);
      for (auto &x : a) cin >> x;
      vector <int64_t> b(n);
      int64_t ans = LLONG_MAX;
      for (int i = 0; i < n; ++i) {
            int64_t cnt = 0;
            vector <int64_t> b(n);
            b[i] = 0;
            if (i != n - 1) {
                  for (int j = i + 1; j < n; ++j) {
                        int64_t tmp = b[j - 1] / a[j] + 1;
                        b[j] = tmp * a[j];
                        cnt += tmp;
                  }
            }
            if (i != 0) {
                  for (int j = i - 1; j >= 0; --j) {
                        int64_t tmp = b[j + 1] / a[j] + 1;
                        b[j] = tmp * a[j];
                        cnt += tmp;
                  }
            }
            ans = min(ans, cnt);
      }
      cout << ans << '\n';
}