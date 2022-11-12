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
 
      int t; cin >> t;
      while (t--) {
            ll n;
            int m; cin >> n >> m;
            vector <ll> a(m); for (auto &x : a) cin >> x;
            if (m == 1) {
                  cout << 2 << '\n';
                  continue;
            }
            vector <ll> segs;
            sort(a.begin(), a.end());
            for (int i = 0; i + 1 < m; ++i) {
                  ll val = a[(i + 1) % m] - a[i] - 1;
                  if (val) segs.push_back(val);
            } 
            ll tmp = a[0] + n - a[m - 1] - 1;
            if (tmp) segs.push_back(tmp);
            sort(segs.rbegin(), segs.rend());
            debug(segs);
            ll ans = 0, days = 0;
            for (int i = 0; i < (int) segs.size(); ++i) {
                  ll curr = segs[i] - 2 * days;
                  if (curr < 1) continue;
                  if (curr < 3) {
                        ans++, days++;
                  } else {
                        ans += curr - 1;
                        days += 2;
                  }
            }
            debug(ans);
            cout << n - ans << '\n';
      }
}