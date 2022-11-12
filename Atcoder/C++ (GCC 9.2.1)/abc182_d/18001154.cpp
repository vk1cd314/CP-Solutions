#include <bits/stdc++.h>

using namespace std;

#ifdef BOI
#include "debug.h"
#else
#define debug(args...)
#endif

typedef long long ll;

int main() {
      ios_base :: sync_with_stdio(0);
      cin.tie(0);

      int n; cin >> n;
      vector <ll> a(n); for (ll& x : a) cin >> x;
      vector <ll> pref(n);
      pref[0] = a[0];
      for (int i = 1; i < n; ++i) pref[i] = pref[i - 1] + a[i];

      ll curr = 0, ans = 0, mx = 0;
      debug(pref);
      for (int i = 0; i < n; ++i) {
            mx = max(mx, pref[i]);
            ans = max(ans, curr + mx);
            curr += pref[i];
      }

      cout << ans << endl;
}
