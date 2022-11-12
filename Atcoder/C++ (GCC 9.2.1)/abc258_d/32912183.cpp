#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif

using namespace std;

#define ll long long

int main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);

      int n; cin >> n;
      ll x; cin >> x;
      vector <pair <ll, ll>> pp(n);
      for (auto &[x, y] : pp) cin >> x >> y;
      ll ans = LLONG_MAX;
      vector <ll> suff(n);
      suff[n - 1] = pp[n - 1].first + pp[n - 1].second;
      for (int i = n - 2; i >= 0; --i) suff[i] = suff[i + 1] + pp[i].first + pp[i].second;

      ll tot = suff[0];
      for (int i = 0; i < n; ++i) {
            ll curr = tot - (i == n - 1 ? 0 : suff[i + 1]);
            curr += max(0ll, x - i - 1) * pp[i].second;
            ans = min(ans, curr);
            curr = tot;
            curr += max(0ll, x - n) * pp[i].second;
            ans = min(ans, curr);
      }
      cout << ans << '\n';

}