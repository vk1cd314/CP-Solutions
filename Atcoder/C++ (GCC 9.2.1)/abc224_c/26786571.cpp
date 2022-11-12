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

      auto nC3 = [&](int64_t n) {
            return (n * (n - 1) * (n - 2)) / 6LL;
      };
 
      int64_t n; cin >> n;
      map <int64_t, int64_t> cntx, cnty;
      vector <pair <int64_t, int64_t>> a;
      for (int i = 0; i < n; ++i) {
            int x, y; cin >> x >> y;
            a.push_back({x, y});
            cntx[x]++, cnty[y]++;
      }
      
      int64_t ans = nC3(n);
 
      map <pair <int64_t, int64_t>, set <pair <int64_t, int64_t>>> lul;
      for (int i = 0; i < n; ++i) {
            map <pair <int64_t, int64_t>, int64_t> dd;
            for (int j = 0; j < n; ++j) {
                  if (i != j) {
                        int64_t dx = a[i].first - a[j].first, dy = a[i].second - a[j].second;
                        int64_t gg = __gcd(dx, dy);
                        pair <int, int> grad = {dx / gg, dy / gg};
                        if (lul[a[i]].find(grad) != lul[a[i]].end() || lul[a[j]].find(grad) != lul[a[j]].end()) continue;
                        lul[a[j]].insert(grad);
                        dd[grad]++;
                  }
            }
            for (auto &[pp, ct] : dd) ans -= nC3(ct + 1); 
      }
 
      cout << ans << '\n';
}