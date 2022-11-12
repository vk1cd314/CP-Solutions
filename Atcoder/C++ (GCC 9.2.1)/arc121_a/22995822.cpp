#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif

using namespace std;

int main() {
      #ifdef Icry
            auto begin = chrono :: high_resolution_clock :: now();
      #endif
      ios_base :: sync_with_stdio(0);
      cin.tie(0);

      int n; cin >> n;
      vector <pair <pair <int64_t, int64_t>, int>> a(n);
      int cnt = 0;
      for (auto &[x, y] : a) cin >> x.first >> x.second, y = cnt++;

      auto b = a;
      sort(a.begin(), a.end(), [&](auto x, auto y) {
            if (x.first.first == y.first.first) return x.first.second > y.first.second;
            return x.first.first > y.first.first;
      });
      sort(b.begin(), b.end(), [&](auto x, auto y) {
            if (x.first.second == y.first.second) return x.first.first > y.first.first;
            return x.first.second > y.first.second;
      });

      debug(a);
      debug(b);

      // int64_t mxX = max(max(abs(a[1].first - a.back().first), abs(a[1].second - a.back().second)),
      //                   max(abs(a[0].first - a[n - 2].first), abs(a[0].second - a[n - 2].second)));
      // int64_t mxY = max(max(abs(b[1].first - b.back().first), abs(b[1].second - b.back().second)),
      //                   max(abs(b[0].first - b[n - 2].first), abs(b[0].second - b[n - 2].second)));

      // int64_t mxX = abs(a[0].first - a.back().first);
      // int64_t mxY = abs(b[0].second - b.back().second);

      // set <pair <int64_t, pair <pair <int64_t, int64_t>, int>>> ss;
      set <pair <pair <int64_t, int64_t>, int>> gg;
      gg.insert(a[0]);
      gg.insert(a[1]);
      gg.insert(a.back());
      if (n > 3) gg.insert(a[n - 2]);
      gg.insert(b[0]);
      gg.insert(b[1]);
      gg.insert(b.back());
      if (n > 3) gg.insert(b[n - 2]);

      auto dist = [&](pair <int64_t, int64_t> x, pair <int64_t, int64_t> y) {
            return max(abs(x.first - y.first), abs(x.second - y.second));
      };

      vector <int64_t> fucc;
      for (auto [x, y] : gg) {
            for (auto [xx, yy] : gg) {
                  if (xx == x && y == yy) continue;
                  int64_t dd = dist(x, xx);
                  fucc.push_back(dd);
            }
      }

      sort(fucc.rbegin(), fucc.rend());
      if (fucc.size() == 1) cout << *fucc.begin() << '\n';
      else {
            debug(fucc);
            auto it = fucc.begin();
            fucc.erase(it);
            it = fucc.begin();
            fucc.erase(it);
            cout << *(fucc.begin()) << '\n';
      }

      // debug(mxX, mxY);
      // cout << max(mxX, mxY) << '\n';

      #ifdef Icry
            auto end = chrono :: high_resolution_clock :: now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << chrono :: duration_cast <chrono :: duration <double>> (end - begin).count() << " seconds]\n";  
      #endif
}