#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
using namespace std;
 
// vector <int> a;
// int n, gg = 0;
// void rec(int i) {
//       if (i == n) {
//             int cnt = 0;
//             int ans = 0;
//             for (int j = 0; j < n; ++j) {
//                   if (a[j] == 1) ++cnt;
//                   else {
//                         ans += cnt / 2;
//                         cnt = 0;
//                   }
//             } 
//             ans += cnt / 2;
//             gg += ans;  
//             return;
//       }
//       a.push_back(1);
//       rec(i + 1);
//       a.pop_back();
//       a.push_back(0);
//       rec(i + 1);
//       a.pop_back();
// }
 
const int mod = 998244353;
 
int64_t binpow(int64_t a, int64_t n, int64_t m = mod) {
      if (n == 0) return 1LL;
      int64_t res = binpow(a, n >> 1LL) % m;
      return (((res * res) % m) * (n & 1 ? a : 1LL)) % m;
}
 
int64_t ded(int64_t n) {
      int64_t curr = (3LL * n + 1) % mod;
      curr = (curr * binpow(2LL, n)) % mod;
      if (n & 1) curr += 1;
      else curr -= 1;
      curr = (curr + mod) % mod;
      curr = (curr * binpow(9LL, mod - 2)) % mod;
      return curr;
}
 
int main() {
      #ifdef Icry
            auto begin = std::chrono::high_resolution_clock::now();
      #endif
      ios_base :: sync_with_stdio(0);
      cin.tie(0);
 
      // for (int i = 1; i <= 10; ++i) {
      //       n = i;
      //       a.clear();
      //       rec(0);
      //       cout << gg << ',';
      //       gg = 0;
      // }
 
      // for (int i = 0; i < 10; ++i) {
      //       debug(ded(i)); 
      // }
 
      // debug(ded(1));
 
      int n, m; cin >> n >> m;
      int tot = 0;
      vector <string> gr(n); for (auto &s : gr) cin >> s, tot += count(s.begin(), s.end(), 'o');
 
      debug(tot);
      int64_t ans = 0;
      for (int i = 0; i < n; ++i) {
            int seg = 0;
            for (int j = 0; j < m; ++j) {
                  if (gr[i][j] == 'o') ++seg;
                  else {
                        debug(seg);
                        if (seg) ans = (ans + ded(seg - 1) * binpow(2LL, tot - seg)) % mod;
                        seg = 0;
                  }
            }
            if (seg) ans = (ans + ded(seg - 1) * binpow(2LL, tot - seg)) % mod;
      }
 
      for (int i = 0; i < m; ++i) {
            int seg = 0;
            for (int j = 0; j < n; ++j) {
                  if (gr[j][i] == 'o') ++seg;
                  else {
                        if (seg) ans = (ans + ded(seg - 1) * binpow(2LL, tot - seg)) % mod;
                        seg = 0;
                  }
            } 
            if (seg) ans = (ans + ded(seg - 1) * binpow(2LL, tot - seg)) % mod;
      }
 
      cout << ans << '\n';
 
      #ifdef Icry
            auto end = std::chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << std::chrono::duration_cast <std::chrono::duration <double>>(end - begin).count() << " seconds]\n";  
      #endif
}
// 0,1,3,9,23,57,135,313,711,1593
// a(n) = ((3*n+1)*2^n - (-1)^n)/9
// https://oeis.org/A045883