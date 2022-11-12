#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
using namespace std;
 
int main() {
      #ifdef Icry
            auto begin = chrono::high_resolution_clock::now();
      #endif
      ios_base::sync_with_stdio(0);
      cin.tie(0);
 
      auto nC3 = [&](int64_t n) {
            return (n * (n - 1) * (n - 2)) / 6LL;
      };
 
      int64_t n; cin >> n;
      map <int, int64_t> cntx, cnty;
      vector <pair <int, int>> a;
      for (int i = 0; i < n; ++i) {
            int x, y; cin >> x >> y;
            a.push_back({x, y});
            cntx[x]++, cnty[y]++;
      }
      
      int64_t ans = nC3(n);
 
      map <pair <int, int>, set <pair <int, int>>> lul;
      for (int i = 0; i < n; ++i) {
            map <pair <int, int>, int> dd;
            for (int j = 0; j < n; ++j) {
                  if (i != j) {
                        int dx = a[i].first - a[j].first, dy = a[i].second - a[j].second;
                        int gg = __gcd(dx, dy);
                        pair <int, int> grad = {dx / gg, dy / gg};
                        if (lul[a[i]].find(grad) != lul[a[i]].end() || lul[a[j]].find(grad) != lul[a[j]].end()) continue;
                        lul[a[j]].insert(grad);
                        dd[grad]++;
                  }
            }
            debug(dd);
            for (auto &[pp, ct] : dd) ans -= nC3(ct + 1); 
      }
 
      cout << ans << '\n';
 
      #ifdef Icry
            auto end = chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << chrono::duration_cast <chrono :: duration <double>> (end - begin).count() << " seconds]\n";  
      #endif
}