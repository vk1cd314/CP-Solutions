#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
using namespace std;
 
const int N = 1e6 + 10;
vector <int> id[N];
 
int main() {
      #ifdef Icry
            auto begin = chrono::high_resolution_clock::now();
      #endif
      ios_base::sync_with_stdio(0);
      cin.tie(0);
 
      srand(time(0));
 
      int n, m; cin >> n >> m;
      int pre[n + 1], a[n];
      for (int i = 0; i < n; ++i) {
            cin >> a[i];
            id[a[i]].push_back(i + 1);    
      }
      for (int i = 1; i < n; ++i) {
            pre[i + 1] = a[i] == a[i - 1] ? pre[i] : i;
      }
 
      auto rangeRand = [&](int l, int r) {
            assert(l <= r);
            return rand() % (r - l + 1) + l;
      };
 
      while (m--) {
            int l, r, x; cin >> l >> r >> x;
            if (id[x].empty()) {
                  cout << rangeRand(l, r) << '\n';
                  continue;
            }
            bool baal = false;
            auto it1 = lower_bound(id[x].begin(), id[x].end(), l);
            auto it2 = lower_bound(id[x].begin(), id[x].end(), r);
            if (it1 == id[x].end()) --it1, baal = true;
            if (it2 == id[x].end() || *it2 > r) --it2;
            int len = (it2 - id[x].begin()) - (it1 - id[x].begin()) + 1;
            if (baal) len = 0;
            debug(len);
            if (len == r - l + 1) cout << "-1\n";
            else {
                  // int ans = rangeRand(l, r);
                  // auto it = lower_bound(id[x].begin(), id[x].end(), ans);
                  // while (3) {
                  //       if (it == id[x].end()) break;
                  //       if (*it != ans) break;
                  //       ans = rangeRand(l, r);
                  //       debug(ans);
                  //       it = lower_bound(id[x].begin(), id[x].end(), ans);
                  // }
                  // cout << ans << '\n';
                  cout << (a[r - 1] == x ? pre[r] : r) << '\n';
            }
      }
 
 
      #ifdef Icry
            auto end = chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << chrono::duration_cast <chrono :: duration <double>> (end - begin).count() << " seconds]\n";  
      #endif
}