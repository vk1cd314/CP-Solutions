#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
using namespace std;
 
int main() {
      #ifdef Icry
            auto begin = std::chrono::high_resolution_clock::now();
      #endif
      ios_base :: sync_with_stdio(0);
      cin.tie(0);
 
      int64_t n, h; cin >> n >> h;
      vector <int64_t> a(n); for (auto &x : a) cin >> x;
 
      debug(a);
      auto req = [&](int x) {
            vector <int> nw;
            for (int i = 0; i < x; ++i) nw.push_back(a[i]);
            sort(nw.rbegin(), nw.rend());
            int64_t ret = 0;
            for (int i = 0; i < x; ++i) {
                  if (i % 2 == 0) ret += nw[i];
            }
            return ret;
      };
 
      int l = 0, r = n + 1;
      while (r - l > 1) {
            debug(l, r);
            int mid = l + r >> 1;
            if (req(mid) <= h) l = mid;
            else r = mid;
      }
 
      cout << l << '\n';
 
      #ifdef Icry
            auto end = std::chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << std::chrono::duration_cast <std::chrono::duration <double>>(end - begin).count() << " seconds]\n";  
      #endif
}