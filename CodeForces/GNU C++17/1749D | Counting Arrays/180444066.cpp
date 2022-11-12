#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
using namespace std;
 
#define ll long long
 
const int MOD = 998244353;
 
ll bp(ll a, ll n, ll m = MOD) {
      if (n == 0) return 1ll;
      ll ret = bp(a, n / 2);
      ret = ret * ret % m;
      if (n & 1) ret = ret * a % m;
      return ret;
}
 
const int N = 1e5 + 10;
bitset <N> prim;
 
void sieve() {      
      prim[1] = 1;
      for (int i = 2; i * i < N; ++i) {
            if (!prim[i]) {
                  for (int j = i * i; j < N; j += i) {
                        prim[j] = 1;
                  }
            }
      }
}
 
int main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
 
      sieve();
 
      ll n, m; cin >> n >> m;
      ll ans = 0, gg = 1, sub = 1;
      for (int i = 1; i <= n; ++i) {
            if (gg > m) {
                  sub = 0;
            } else {
                  if (!prim[i]) gg = gg * i;
                  ll mul = m / gg % MOD;
                  sub = sub * mul % MOD; 
            }
            ll tmp = bp(m % MOD, i);
            debug(i, tmp, sub, gg);
            tmp = (tmp - sub + MOD) % MOD;
            debug("after", tmp);
            ans = (ans + tmp) % MOD;
      }
      cout << ans << '\n';
}