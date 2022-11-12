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
            int n, m; cin >> n >> m;
            vector <int> a(n); for (int &x : a) cin >> x;
            map <int64_t, int64_t> cnt;
            for (int &x : a) x %= m;
            for (int x : a) cnt[x]++;
            map <pair <int, int>, int64_t> ans;
 
            sort(a.begin(), a.end());
            debug(cnt);
            for (int x : a) {
                  if (x == (m - x) % m) {
                        if (cnt[x]) cnt[x]--, ans[{x, x}]++;
                  } else if (cnt[x] > 0 && cnt[(m - x) % m] > 0) {
                        cnt[x]--;
                        cnt[(m - x) % m]--;
                        ans[{min(x, (m - x) % m), max(x, (m - x) % m)}] += 2;
                  } else if (ans.count({min(x, (m - x) % m), max(x, (m - x) % m)})) {
                        if (ans[{min(x, (m - x) % m), max(x, (m - x) % m)}] % 2 == 0 && cnt[x] > 0) cnt[x]--, ans[{min(x, (m - x) % m), max(x, (m - x) % m)}]++;
                  }
            }
            debug(cnt);
            debug(ans);
            int ext = 0;
            for (auto [dd, xx] : cnt) ext += xx;
            debug(ext);
            cout << (int) ans.size() + ext << '\n';
      }
 
      #ifdef Icry
            auto end = std::chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << std::chrono::duration_cast <std::chrono::duration <double>>(end - begin).count() << " seconds]\n";  
      #endif
}