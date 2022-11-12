#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...)
#endif
 
using namespace std;
 
int main() {
#ifdef Icry
      auto begin = chrono ::high_resolution_clock ::now();
#endif
      ios_base ::sync_with_stdio(0);
      cin.tie(0);
 
      int t;
      cin >> t;
      while (t--) {
            int n;
            cin >> n;
            vector<int64_t> a(n), nega;
            int neg = 0, pos = 0, zero = 0;
            for (auto &x : a) cin >> x;
            sort(a.begin(), a.end());
 
            int64_t mi = LLONG_MAX;
            for (int i = 0; i < n; ++i) {
                  if (a[i] < 0) {
                        neg++;
                        nega.push_back(a[i]);
                  } else if (a[i] > 0) pos++;
                  else zero++;
 
                  if (a[i] > 0) mi = min(a[i], mi);
            }
 
            sort(nega.rbegin(), nega.rend());
            int x = 0, temp = 0;
            if (zero > 0) temp = 0;
            else temp = mi;
            for (int i = 0; i < neg; ++i) {
                  if (abs(nega[i] - temp) >= mi) {
                        temp = nega[i];
                        x++;
                  }
            }
            int ans = 1;
            if (neg == x) {
                  if (pos > 0 && zero > 0) ans = max(1 + 1 + neg, ans);
                  if (zero > 0) ans = max(ans, zero + neg);
                  if (pos > 0) ans = max(ans, 1 + neg);
                  ans = max(ans, neg);
            } else {
                  ans = max(zero + neg, ans);
            }
 
            cout << ans << '\n';
      }
 
#ifdef Icry
      auto end = chrono ::high_resolution_clock ::now();
      cerr << setprecision(4) << fixed;
      cerr << "[Execution time: " << chrono ::duration_cast<chrono ::duration<double>>(end - begin).count() << " seconds]\n";
#endif
}