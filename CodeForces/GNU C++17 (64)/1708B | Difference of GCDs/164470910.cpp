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
            long long n, l, r; cin >> n >> l >> r;
            // gcd(a[i] / i, 1) == 1
            // r / n - (l - 1) / n
            bool ok = true;
            vector <long long> a(n);
            for (long long i = 0; i < n; ++i) {
                  if (r / (i + 1) - (l - 1) / (i + 1) < 1) ok = false;
                  a[i] = (l + i) / (i + 1) * (i + 1); 
                  // l <= k * i <= r
                  // l / i <= k <= r / i
            }
            if (!ok) cout << "NO\n";
            else {
                  cout << "YES\n";
                  for (int x : a) cout << x << ' ';
                  cout << '\n';
            }
      }
}