#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
using namespace std;
 
int main() {
      // ios_base::sync_with_stdio(0);
      // cin.tie(0);
 
      int t; cin >> t;
      while (t--) {
            int n; cin >> n;
            int l = 1, r = n;
            auto check = [&](int l, int r) {
                  cout << "? " << l << ' ' << r << endl;
                  int cnt = 0;
                  for (int i = l; i <= r; ++i) {
                        int x; cin >> x;
                        cnt += (l <= x && x <= r);
                  }
                  return cnt % 2;
            };
            while (r - l > 1) {
                  int m = l + r >> 1;
                  if (check(l, m)) r = m;
                  else l = m;
            }
            int c = check(l, l);
            cout << "! ";
            cout << (c ? l : r) << endl;
      }
}
// 4 2 5 1 3