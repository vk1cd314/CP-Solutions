#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
using namespace std;
 
const int MOD = 998244353;
const int N = 1e3 + 10;
int64_t fac[N];
 
int main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
 
      fac[0] = 1;
      for (int i = 1; i < N; ++i) fac[i] = (fac[i - 1] * i) % MOD;
 
      int t; cin >> t;
      while (t--) {
            int64_t n; cin >> n;
            if (n & 1) {
                  cout << "0\n";
                  continue;
            }
            cout << (fac[n / 2] * fac[n / 2]) % MOD << '\n';
      }
}