#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
#define ll long long
 
using namespace std;
 
int main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
 
      int n, q; cin >> n >> q;
      vector <ll> a(n); for (ll &x : a) cin >> x;
      map <int, ll> mp;
      ll sum = 0, cc = 0;
      for (int i = 0; i < n; ++i) mp[i] = a[i], sum += a[i];
 
      while (q--) {
            int t; cin >> t;
            if (t == 1) {
                  int i; ll x; cin >> i >> x; --i;
                  sum += x - (mp[i] ? mp[i] : cc);
                  mp[i] = x;
            } else {
                  ll x; cin >> x;
                  sum = x * n;
                  cc = x;
                  mp.clear();
            }
            cout << sum << '\n';
      }
}