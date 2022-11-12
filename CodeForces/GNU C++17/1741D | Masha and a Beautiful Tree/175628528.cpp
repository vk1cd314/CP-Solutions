#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
using namespace std;
 
bool ok = true;
vector <int> a;
 
pair <int, int> rec(int l, int r) {
      if (r - l + 1 == 2) {
            if (max(a[l], a[l + 1]) % 2) ok = false;
            if (abs(a[l] - a[l + 1]) != 1) ok = false;
            debug(l, r, ok);
            return {a[l] > a[l + 1], max(a[l], a[l + 1])};
      }
      int m = (l + r) / 2;
      pair <int, int> lft = rec(l, m), rgt = rec(m + 1, r);
      int lftmx = lft.second / 2, rgtmx = rgt.second / 2;
      if (max(lftmx, rgtmx) % 2) ok = false;
      if (abs(lftmx - rgtmx) != 1) ok = false;
      debug(l, r, ok);
      return {lft.first + rgt.first + (lftmx > rgtmx), max(lftmx, rgtmx)};
}
 
int main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
 
      int t; cin >> t;
      while (t--) {
            int n; cin >> n;
            a.assign(n, 0); for (int &x : a) cin >> x;
            if (n < 4) {
                  if (n == 1) cout << "0\n";
                  else if (n == 2) {
                        if (a[0] == 2) cout << "1\n";
                        else cout << "0\n";
                  }
                  continue;
            }
            ok = true;
            auto [x, y] = rec(0, n - 1);
            if (!ok) cout << "-1\n";
            else cout << x << '\n';
      }
}