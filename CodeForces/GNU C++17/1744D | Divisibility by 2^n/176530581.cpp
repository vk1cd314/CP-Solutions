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
            ll n; cin >> n;
            vector <ll> a(n); for (auto &x : a) cin >> x;
            ll p2 = 0;
            for (auto x : a) {
                  ll ct = 0;
                  while (x % 2 == 0) x /= 2, ct++;
                  p2 += ct;
            }
            vector <ll> pps;
            for (int i = 1; i <= n; ++i) {
                  ll tmp = i, ct = 0;
                  while (tmp % 2 == 0) tmp /= 2, ct++;
                  if (ct) pps.push_back(ct); 
            }
            sort(pps.rbegin(), pps.rend());
            ll need = n - p2;
            if (need <= 0) {
                  cout << "0\n";
                  continue;
            }
            ll ans = 0;
            debug(need);
            debug(pps);
            for (int i = 0; i < (int) pps.size(); ++i) {
                  if (!need) break;
                  ll take = min(need, pps[i]);
                  need -= take;
                  ans += 1;
            }
            if (need > 0) {
                  cout << "-1\n";
                  continue;
            }
            cout << ans << '\n';
      }
}