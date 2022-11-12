#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
using namespace std;
 
long double v;
int f;
bool done;
const long double eps = 1e-10;
 
long double rec(int x, long double c, long double m) {
      if (x + 1 == f) {
            done = true;
            return 1.0 - c - m;
      }
      long double ret = 1, r1 = c, r2 = m;
      long double _c = c, _m = m;
      if (!(c < eps)) {
            // debug(c);
            if (c <= v) {
                  if (!(m < eps)) m += c / 2;
                  c = 0;
            }
            else {
                  c -= v;
                  if (!(m < eps)) m += v / 2;
            }
            r1 *= rec(x + 1, c, m);
      }
      if (!(_m < eps)) {
            // debug(_m);
            if (_m <= v) {
                  if (!(_c < eps)) _c += _m / 2;
                  _m = 0;
            }
            else {
                  _m -= v;
                  if (!(_c < eps)) _c += v / 2;
            }
            r2 *= rec(x + 1, _c, _m);
      }
      ret *= (r1 + r2); 
      return ret;
}
 
int main() {
      #ifdef Icry
            auto begin = chrono::high_resolution_clock::now();
      #endif
      ios_base::sync_with_stdio(0);
      cin.tie(0);
 
      int t; cin >> t;
      while (t--) {
            long double c, m, p; cin >> c >> m >> p;
            cin >> v;
            long double ans = 0;
            for (int i = 1; i <= 20; ++i) {
                  f = i;
                  done = false;
                  long double ff = rec(0, c, m);
                  if (!done) break;
                  // debug(f, ff);
                  ans += 1.0 * f * ff;
            }
            cout << fixed << setprecision(10) << ans << '\n';
      }
      // wow man precision does matter
 
      #ifdef Icry
            auto end = chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << chrono::duration_cast <chrono :: duration <double>> (end - begin).count() << " seconds]\n";  
      #endif
}