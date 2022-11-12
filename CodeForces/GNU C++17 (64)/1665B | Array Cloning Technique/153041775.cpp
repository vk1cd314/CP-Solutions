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
            int n; cin >> n;
            map <int64_t, int> ct;
            vector <int64_t> a(n); for (auto &x : a) cin >> x, ct[x]++;
            sort(a.begin(), a.end());
            int mn = INT_MAX;
            for (auto [x, y] : ct) {
                  int64_t need = n - y;
                  if (!need) {
                        mn = 0;
                        break;
                  }
                  int64_t have = y;
                  int ops = 0;
                  while (need != 0) {
                        ops++;
                        int64_t take = min(have, need);
                        need -= take;
                        ops += take;
                        have = n - need;
                  }
                  mn = min(mn, ops);
            }
            cout << mn << '\n';
      }
}
// 0 1 3 3 7 0
// 