#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif

using namespace std;

const int MOD = 998244353, inv2 = (MOD + 1) / 2;

long long binpow(long long a, long long n, long long m = MOD) {
      if (n == 0) return 1LL;
      long long res = binpow(a, n >> 1LL) % m;
      return (((res * res) % m) * (n & 1 ? a : 1LL)) % m;
}

signed main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);

      int n, m; cin >> n >> m;
      vector <int> p(n); for (int &x : p) cin >> x, --x;
      vector <bool> vis(n, false);
      int cnt = 0;
      for (int i = 0; i < n; ++i) {
            if (vis[i]) continue;
            int j = i;
            while (!vis[j]) {
                  vis[j] = true;
                  j = p[j];
            }
            ++cnt;
      }
      long long ans = (binpow(m, n) - binpow(m, cnt) + MOD) % MOD;
      cout << ans * inv2 % MOD << '\n';
}