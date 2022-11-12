#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
using namespace std;
 
int main() {
      #ifdef Icry
            auto begin = chrono :: high_resolution_clock :: now();
      #endif
      ios_base :: sync_with_stdio(0);
      cin.tie(0);
 
      int t; cin >> t;
      while (t--) {
            int64_t n, l, r; cin >> n >> l >> r;
            vector <int64_t> a(n); for (auto &x : a) cin >> x;
            sort(a.begin(), a.end());
 
            int64_t ans = 0;
            for (int i = 0; i < n; ++i) {
                  if (i == 0) continue;
                  auto it = upper_bound(a.begin(), a.begin() + i, r - a[i]);
                  if (it == a.begin()) continue;
                  --it;
                  int64_t rr = it - a.begin();
                  it = lower_bound(a.begin(), a.begin() + i, l - a[i]);
                  int64_t ll = it - a.begin();
                  ans += rr - ll + 1;
            }
            cout << ans << '\n';
      }
 
      #ifdef Icry
            auto end = chrono :: high_resolution_clock :: now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << chrono :: duration_cast <chrono :: duration <double>> (end - begin).count() << " seconds]\n";  
      #endif
}