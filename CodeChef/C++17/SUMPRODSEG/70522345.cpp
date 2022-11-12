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
            long long x, y; cin >> x >> y;
            // (0, x) (1, x - 1), (2, x - 2) 
            // 3 = 1 + 2 [1, 2]
            // 4 = 2 + 2 [2, 2]
            long long xx = x / 2;
            long long yy = x - xx;
            pair <long long, long long> mm = {min(xx, yy), max(xx, yy)};
            debug(mm);
            bool found = false;
            pair <long long, long long> p1 = {-1, -1}, p2 = {-1, -1};
            for (long long i = 1; i * i <= y && !found; ++i) {
                  if (y % i == 0) {
                        long long f1 = i, f2 = y / i;
                        pair <long long, long long> curr = {min(f1, f2), max(f1, f2)};
                        long long dd1 = max(curr.first, mm.first), dd2 = min(curr.second, mm.second);
                        long long dist = max(0ll, dd2 - dd1 + 1);
                        debug(dd1, dd2);
                        if (!dist) {
                              p1 = mm;
                              p2 = curr;
                              debug(p1, p2);
                              found = true;
                        }
                  }
            }
            if (!found) cout << "-1\n";
            else {
                  cout << p1.first << ' ' << p1.second << '\n';
                  cout << p2.first << ' ' << p2.second << '\n';
            } 
      }
}