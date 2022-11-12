#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
using namespace std;
 
// const int N = 2e5 + 10;
const int mod = 1e9 + 7;
// int64_t fac[N];
//  invFac[N];
 
// int64_t binpow(int64_t a, int64_t n, int64_t m = mod) {
//       if (n == 0) return 1LL;
//       int64_t res = binpow(a, n >> 1LL) % m;
//       return (((res * res) % m) * (n & 1 ? a : 1LL)) % m;
// }
 
int main() {
      #ifdef Icry
            auto begin = std::chrono::high_resolution_clock::now();
      #endif
      ios_base :: sync_with_stdio(0);
      cin.tie(0);
 
      // fac[0] = 1LL;
      // for (int i = 1; i < N; ++i) fac[i] = (fac[i - 1] * 1LL * i) % mod;
      // invFac[N - 1] = binpow(fac[N - 1], mod - 2, mod);
      // for (int i = N - 2; i >= 0; ++i) invFac[i] = (invFac[i + 1] * 1LL * (i + 1)) % mod;
 
      int t; cin >> t;
      while (t--) {
            int n; cin >> n;
            map<int64_t,int64_t> cnt;
            vector <int64_t> a(n); for (auto &x : a) cin >> x, cnt[x]++;
            int64_t sum;
            for(int i = 0;i < n; ++i) {
                  if(!i) {
                        sum = a[i];
                  }
                  sum &= a[i];
            }
            int64_t ans = cnt[sum] * (cnt[sum] - 1);
            ans = ans % mod;
            for(int64_t i = 1; i < n - 1; ++i) {
                  ans = (ans * i) % mod;
            }
            cout << ans << '\n';
      }
 
      // 1 3 5 1 - (1, 2, 3, 4)
      // 1 3 5 1 - (4, 2, 3, 1)
      // 1 5 3 1 - (1, 3, 2, 4)
      // 1 5 3 1 - (4, 3, 2, 1)
      // 0      0 
      // 3! * 3C2 * 2
 
 
      #ifdef Icry
            auto end = std::chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << std::chrono::duration_cast <std::chrono::duration <double>>(end - begin).count() << " seconds]\n";  
      #endif
}