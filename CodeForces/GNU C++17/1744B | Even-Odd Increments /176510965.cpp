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
            int n, q; cin >> n >> q;
            ll ct0 = 0, ct1 = 0, ss0 = 0, ss1 = 0;
            vector <ll> a(n); for (auto &x : a) {
                  cin >> x;
                  if (x & 1) {
                        ss1 += x;
                        ct1++;
                  } else {
                        ct0++;
                        ss0 += x;
                  }
            }
            while (q--) {
                  int tt; cin >> tt;
                  if (!tt) {
                        ll x; cin >> x;
                        if (x & 1) {
                              ss1 = ss1 + ss0 + ct0 * x;
                              ss0 = 0;
                              ct0 = 0;
                              ct1 = n;
                        } else {
                              ss0 = ss0 + x * ct0;
                        }
                  } else {
                        ll x; cin >> x;
                        if (x & 1) {
                              ss0 = ss0 + ss1 + ct1 * x;
                              ss1 = 0;
                              ct1 = 0;
                              ct0 = n;
                        } else {
                              ss1 = ss1 + x * ct1;
                        }
                  }
                  cout << (ss1 + ss0) << '\n';
            }
      }
}