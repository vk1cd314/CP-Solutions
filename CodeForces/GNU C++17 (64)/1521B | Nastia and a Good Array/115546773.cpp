#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
using namespace std;
 
int64_t pp = 1e9 + 7;
 
int main() {
      #ifdef Icry
            auto begin = chrono :: high_resolution_clock :: now();
      #endif
      ios_base :: sync_with_stdio(0);
      cin.tie(0);
 
      int t; cin >> t;
      while (t--) {
            int n; cin >> n;
            vector <int64_t> a(n); for (auto &x : a) cin >> x;
 
            vector <tuple <int, int, int64_t, int64_t>> ops;
            for (int i = 0; i < n; i += 2) {
                  if (i + 1 >= n) break;
                  int64_t mi = min(a[i], a[i + 1]);
                  int64_t x = mi, y = pp;
                  ops.emplace_back(i + 1, i + 2, x, y);
            }
 
            assert(ops.size() <= n);
            cout << ops.size() << '\n';
            for (auto [i, j, x, y] : ops) {
                  cout << i << ' ' << j << ' ' << x << ' ' << y << '\n';
            }
      }
 
      #ifdef Icry
            auto end = chrono :: high_resolution_clock :: now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << chrono :: duration_cast <chrono :: duration <double>> (end - begin).count() << " seconds]\n";  
      #endif
}