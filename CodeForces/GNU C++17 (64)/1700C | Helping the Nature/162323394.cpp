#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
using namespace std;
 
int main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
 
      int t; cin >> t;
      while (t--) {
            int n; cin >> n;
            vector <long long> a(n); for (auto &x : a) cin >> x;
            long long ans = 0;
            long long ch = a[0];
            for (int i = 0; i + 1 < n; ++i) {
                  ans += abs(a[i] - a[i + 1]);
                  if (a[i] > a[i + 1]) {
                        ch -= a[i] - a[i + 1];
                  }
            }
            ans += abs(ch);
            cout << ans << '\n';
      }
}