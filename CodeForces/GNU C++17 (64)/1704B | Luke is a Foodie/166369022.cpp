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
            int n; 
            ll x; cin >> n >> x;
            vector <ll> a(n); for (auto &x : a) cin >> x;
            int segs = 0;
            for (int i = 0; i < n; ++i) {
                  int j = i;
                  pair <ll, ll> rng = {a[i] - x, a[i] + x};
                  while (j + 1 < n) {
                        pair <ll, ll> nn = {a[j + 1] - x, a[j + 1] + x};
                        ll r1 = max(rng.first, nn.first);
                        ll l1 = min(rng.second, nn.second);
                        ll len = max(0ll, l1 - r1 + 1);
                        if (!len) break;
                        rng = {r1, l1};
                        ++j;
                  }
                  i = j;
                  ++segs;
            }
            debug(segs);
            assert(segs != 0);
            cout << segs - 1 << '\n';
      }
}