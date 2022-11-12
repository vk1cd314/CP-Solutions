#include <bits/stdc++.h>

using namespace std;

#ifdef BOI
#include "debug.h"
#else
#define debug(args...)
#endif

typedef long long ll;

ll sum(ll x) {
      return (x * (x + 1)) / 2;
}

int main() {
      ios_base :: sync_with_stdio(0);
      cin.tie(0);

      ll n; cin >> n;

      ll x = 0;
      while (sum(x) <= n + 1) ++x;
      --x;
      ll ans = n - x + 1;
      
      cout << ans << endl;
}
