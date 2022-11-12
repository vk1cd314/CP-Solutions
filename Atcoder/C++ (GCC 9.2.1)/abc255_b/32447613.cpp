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

      int n, k; cin >> n >> k;
      vector <int> a(k); for (int &x : a) cin >> x, --x;
      vector <pair <double, double>> p(n);
      for (auto &[x, y] : p) cin >> x >> y;
      debug(a);
      debug(p);

      auto f = [&](double r) {
            vector <bool> ok(n, false);
            for (int x : a) {
                  for (int i = 0; i < n; ++i) {
                        if (ok[i]) continue;
                        double d = (p[i].first - p[x].first) * (p[i].first - p[x].first) + (p[i].second - p[x].second) * (p[i].second - p[x].second);
                        d = sqrt(d);
                        if (d <= r) ok[i] = true;
                  }
            }
            for (bool b : ok) if (!b) return false;
            return true;
      };

      double l = 0, r = 1e7;
      int bb = 200;
      while (bb--) {
            double m = (l + r) / 2;
            if (f(m)) r = m;
            else l = m;
      }
      cout << fixed << setprecision(10);
      cout << r << '\n';
}