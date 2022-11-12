#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
using namespace std;
 
#define ll long long
 
const int MOD = 1e9 + 7;
 
const int N = 31622776 + 20;
vector <int> primes;
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
 
      for (int i = 2; i < N; ++i) {
            if (!prim[i]) primes.push_back(i);
      }
}
 
ll binpow(ll a, ll n, ll m = MOD) {
      if (n == 0) return 1LL;
      ll res = binpow(a, n >> 1LL) % m;
      return (((res * res) % m) * (n & 1 ? a : 1LL)) % m;
}
 
int main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
 
      sieve();
 
      ll n, k; cin >> n >> k;
      auto fac = [&](ll x) {
            vector <pair <ll, ll>> ret;
            for (int i = 0; primes[i] * 1ll * primes[i] <= x; ++i) {
                  int ct = 0;
                  while (x % primes[i] == 0) x /= primes[i], ct++;
                  if (ct) ret.push_back({primes[i], ct});
            }
            if (x > 1) ret.push_back({x, 1});
            return ret;
      };
      auto facs = fac(n);
      debug(facs);
      ll ans = 1;
      for (auto [p, x] : facs) {
            vector <vector <ll>> dp(k + 1, vector <ll>(x + 1));
            for (int i = 0; i <= x; ++i) dp[0][i] = binpow(p, i);
            // dp[x][0] = 1; 
            debug(dp[0]);
            for (int i = 1; i <= k; ++i) {
                  ll tot = 0;
                  for (int j = 0; j <= x; ++j) {
                        // dp[i][j] = 1 / (j + 1) sum dp[i - 1][j1]
                        tot = (tot + dp[i - 1][j]) % MOD;
                        debug(j, tot);
                        dp[i][j] = tot;
                        dp[i][j] = dp[i][j] * binpow(j + 1, MOD - 2) % MOD;
                  }
                  debug(dp[i]);
            }
            ans = ans * dp[k][x] % MOD;
      }
      cout << ans << '\n';
}