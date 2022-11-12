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
            int64_t n, a, b; cin >> n >> a >> b;
            vector <int64_t> x(n); for (auto &xx : x) cin >> xx;
            vector <int64_t> pre(n);
            pre[0] = x[0];
            for (int i = 1; i < n; ++i) pre[i] = pre[i - 1] + x[i];
            int64_t curr = 0;
            int64_t ans = 0;
            for (int i = 0; i < n; ++i) {
                  int64_t conq = b * (x[i] - curr);
                  int64_t left = pre[n - 1] - (i ? pre[i - 1] : 0); // [i, n - 1]
                  int64_t currCost = b * (left - (n - i) * curr);
                  int64_t left1 = pre[n - 1] - pre[i]; // [i + 1, n - 1]
                  int64_t capCost = conq + a * (x[i] - curr) + b * (left1 - (n - i - 1) * x[i]);
                  // debug(i, x[i], curr, capCost, currCost);
                  // debug(curr);
                  if (capCost <= currCost) {
                        // debug(conq);
                        // debug(a * (x[i] - curr));
                        ans += conq + a * (x[i] - curr);
                        curr = x[i];
                        // debug(conq + a * (x[i] - curr));
                  } else {
                        // debug(conq);
                        ans += conq;
                  }
            }
            cout << ans << '\n';
      }
}
// b * (x1 - curr)
// b * (x2 - curr)