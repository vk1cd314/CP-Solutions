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
            ll sum = 0;
            ll ans = n;
            for (int i = 0; i < n; ++i) {
                  sum += a[i];
                  int j = i + 1, lst = i;
                  vector <pair <ll, int>> ff;
                  ff.push_back({sum, i + 1});
                  ll csum = 0;
                  while (j < n) {
                        csum += a[j];
                        if (csum >= sum) {
                              ff.push_back({csum, j - lst});
                              lst = j;
                              csum = 0;
                        }
                        j++;
                  }
                  if (csum) ff.push_back({csum, n - 1 - lst});
                  debug(ff);
                  bool ok = true;
                  ll mx = -1;
                  for (auto [x, y] : ff) {
                        if (x != sum) {
                              ok = false;
                              break;
                        }
                        mx = max(mx, (ll)y);
                  }
                  if (!ok) continue;
                  ans = min(ans, mx);
            }
            cout << ans << '\n';
      }
}