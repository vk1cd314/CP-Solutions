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
 
      int t; cin >> t;
      while (t--) {
            int n; cin >> n;
            int64_t w; cin >> w;
            vector <int64_t> W(n); for (auto &x : W) cin >> x;
            multiset <int64_t> ded;
            for (auto x : W) ded.insert(x);
 
            debug(ded);
            int64_t tmp = w, ans = 0;
            while (3) {
                  if (ded.empty()) break;
                  auto ff = *ded.rbegin(); ded.erase(--ded.end());
                  tmp -= ff;
                  if (tmp < 0) {
                        tmp = w;
                        ded.insert(ff);
                        ++ans;
                        continue;
                  }
                  while (tmp > 0 && !ded.empty()) {
                        auto it = ded.lower_bound(tmp);
                        if (it == ded.begin() && *it > tmp) break;
                        if (it == ded.end() || *it > tmp) --it;
                        tmp -= *it;
                        ded.erase(it);
                  }
            }
            cout << ans + (tmp >= 0) << '\n';
      }
 
      #ifdef Icry
            auto end = std::chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << std::chrono::duration_cast <std::chrono::duration <double>>(end - begin).count() << " seconds]\n";  
      #endif
}