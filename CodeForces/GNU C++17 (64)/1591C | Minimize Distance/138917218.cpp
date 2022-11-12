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
            int n, k; cin >> n >> k;
            vector <int64_t> left, right;
            left.push_back(0);
            right.push_back(0);
            for (int i = 0; i < n; ++i) {
                  int x; cin >> x;
                  if (x < 0) left.push_back(-x);
                  else right.push_back(x);
            }
            sort(left.begin(), left.end());
            sort(right.begin(), right.end());
            // vector <int64_t> pl(left.size()), pr(right.size());
            // pl[0] = left[0], pr[0] = right[0];
            // for (int i = 1; i < (int) left.size(); ++i) {
            //       pl[i] = pl[i - 1] + left[i];
            // }
            // for (int i = 1; i < (int) right.size(); ++i) {
            //       pr[i] = pr[i - 1] + right[i];
            // }
            debug(left, right);
            int id = 0, szl = left.size(), szr = right.size();
            vector <int64_t> pp;
            id = szr - 1;
            while (id >= 1) {
                  pp.push_back(right[id]);
                  id -= k;
            }
            id = szl - 1;
            while (id >= 1) {
                  pp.push_back(left[id]);
                  id -= k;
            }
 
            sort(pp.begin(), pp.end());
            int64_t ans = accumulate(pp.begin(), pp.end(), 0LL) * 2 - pp.back();
 
            cout << ans << '\n';
 
            // if (left.size() == 1) cout << c1 << '\n';
            // else if (right.size() == 1) cout << c2 << '\n';
            // else {
            //       cout << min(c1 + right[szr - 1] + c2, c2 + left[szl - 1] + c1) << '\n';
            // }
 
      }
}
// 1 * 2 + 2 * 2 + 