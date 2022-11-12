#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif

using namespace std;

const int mod = 998244353;

int n;
vector <int64_t> a;
// vector <pair <int64_t, int>> curr;
// map <pair <int, int>, int> cnt;
// int64_t ans = 0;
// void rec(int i) {
//       if (i == n) {
//             if (curr.empty()) return;
//             auto it1 = *max_element(curr.begin(), curr.end());
//             auto it2 = *min_element(curr.begin(), curr.end());
//             ans += it1.first * it2.first;
//             cnt[{it1.second, it2.second}]++;
//             return;
//       }
//       curr.push_back({a[i], i + 1});
//       rec(i + 1);
//       curr.pop_back();
//       rec(i + 1);
// }

int main() {
      #ifdef Icry
            auto begin = std::chrono::high_resolution_clock::now();
      #endif
      ios_base :: sync_with_stdio(0);
      cin.tie(0);

      cin >> n;
      a.assign(n, 0LL);
      for (auto &x : a) cin >> x;
      sort(a.begin(), a.end());
      // rec(0);
      // debug(ans);
      // debug(a);
      // for (auto [x, y] : cnt) {
      //       if (x.first != x.second) {
      //             debug(x, y);
      //             // cout << y << ' ';
      //       }
      // }

      int64_t pre = 0, ans = (a[0] * a[0]) % mod;
      for (int i = 1; i < n; ++i) {
            pre = (2LL * pre) % mod;
            pre = (pre + a[i - 1]) % mod;
            ans = (ans + (pre * a[i]) % mod) % mod;
            ans = (ans + (a[i] * a[i]) % mod) % mod;
      }

      cout << ans << '\n';

      #ifdef Icry
            auto end = std::chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << std::chrono::duration_cast <std::chrono::duration <double>>(end - begin).count() << " seconds]\n";  
      #endif
}