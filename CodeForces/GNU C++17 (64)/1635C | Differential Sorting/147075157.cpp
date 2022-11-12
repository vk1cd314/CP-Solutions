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
            vector <int> a(n); for (int &x : a) cin >> x;
            if (is_sorted(a.begin(), a.end())) {
                  cout << "0\n";
                  continue;
            }
            // vector <pair <int, int>> suffmin(n), suffmax(n);
            // suffmin[n - 2] = {a[n - 2], n - 2};
            // suffmax[n - 2] = {a[n - 2], n - 2};
            // for (int i = n - 3; i >= 0; --i) {
            //       suffmin[i] = suffmin[i + 1];
            //       if (a[i] < suffmin[i].first) suffmin[i] = {a[i], i};
            //       suffmax[i] = suffmax[i + 1];
            //       if (a[i] > suffmax[i].first) suffmax[i] = {a[i], i};
            // }
            if (a[n - 2] > a[n - 1]) cout << "-1\n";
            else {
                  vector <tuple <int, int, int>> ops;
                  for (int i = 0; i + 2 < n; ++i) {
                        int x = i, y = n - 2, z = n - 1;
                        a[x] = a[y] - a[z];
                        ops.push_back({x, y, z});
                  }
                  if (is_sorted(a.begin(), a.end())) {
                        cout << ops.size() << '\n';
                        for (auto [x, y, z] : ops) cout << x + 1 << ' ' << y + 1 << ' ' << z + 1 << '\n';
                  } else cout << "-1\n";
            }
      }
}