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
      here: while (t--) {
            int n; cin >> n;
            vector <long long> a(n); for (auto &x : a) cin >> x;
            int ans = 0;
            for (int i = n - 1; i >= 1; --i) {
                  if (!a[i]) {
                        cout << "-1\n";
                        goto here;
                  }
                  while (a[i] <= a[i - 1]) a[i - 1] /= 2, ans++; 
            }
            cout << ans << '\n';
      }
}