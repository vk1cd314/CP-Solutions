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

      int64_t pow[5] = {1, 10, 100, 1000, 10000};
      int k; cin >> k;
      map <int, int> cnt, cnt1;
      string s, t; cin >> s >> t;
      for (char c : s) cnt[c - '0']++;
      for (char c : t) cnt1[c - '0']++;

      cnt['#' - '0'] = 0;
      cnt1['#' - '0'] = 0;

      int64_t currs = 0, currt = 0;
      for (int i = 1; i <= 9; ++i) {
            currs += i * pow[cnt[i]];
            currt += i * pow[cnt1[i]];
      }

      map <int, int> have;
      int64_t tot = 0, lel = 0;
      for (int i = 1; i <= 9; ++i) {
            have[i] = k - cnt[i] - cnt1[i];
            lel += have[i];
      }
      debug(have);
      debug(currs, currt, lel);

      int64_t dud = 0;
      long double ans = 0;
      for (auto [x, y] : have) {
            if (y == 0) continue;
            int64_t extra = 9LL * x * pow[cnt[x]];
            for (auto [a, b] : have) {
                  if ((x == a && y == 1) || (b == 0)) continue;
                  int64_t extra1 = 9LL * a * pow[cnt1[a]];
                  // debug(x, a, extra, extra1);
                  if (currs + extra > currt + extra1) {
                        ++dud;
                        if (x != a) ans += (double(y) / double(lel - 1)) * (double(b) / double(lel));
                        else ans += (double(y) / double(lel - 1)) * (double(b - 1) / double(lel));
                        debug(x, a, extra, extra1);
                  }
                  ++tot;
            }
      }

      debug(dud, tot);
      // long double ans = double(dud) / double(tot);
      cout << fixed << setprecision(10) << ans << '\n';
      #ifdef Icry
            auto end = std::chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << std::chrono::duration_cast <std::chrono::duration <double>>(end - begin).count() << " seconds]\n";  
      #endif
}