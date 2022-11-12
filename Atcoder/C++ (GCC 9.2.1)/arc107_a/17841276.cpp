#include <bits/stdc++.h>

using namespace std;

#ifdef BOI
#include "debug.h"
#else
#define debug(args...)
#endif

typedef long long ll;

const ll mod = 998244353;

ll nC2(ll n) {
      ll ret = n;
      ret *= (n + 1);
      ret /= 2;
      ret %= mod;
      return ret;
}

int main() {
      ios_base :: sync_with_stdio(0);
      cin.tie(0);

      ll a, b, c; cin >> a >> b >> c;

      ll ans = nC2(a);
      ans = ans * nC2(b) % mod;
      ans = ans * nC2(c) % mod;
      
      cout << ans << endl;
}
