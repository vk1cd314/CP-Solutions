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
            vector <int64_t> a(n); for (auto &x : a) cin >> x;
            vector <int> lol; 
            for (int i = 1; i < n - 1; ++i) {
                  if (a[i - 1] < a[i] && a[i] > a[i + 1]) lol.push_back(i);
            }
            // debug(a);
            // debug(lol);
            int ans = 0;
            int sz = lol.size();
            for (int i = 0; (int) i < sz; ++i) {
                  if (i + 1 < sz && lol[i] + 2 == lol[i + 1]) { 
                        a[lol[i] + 1] = max(a[lol[i]], a[lol[i + 1]]); 
                        ans++;
                        i++;
                  } else {
                        a[lol[i]] = max(a[lol[i] - 1], a[lol[i] + 1]);
                        ans++;
                  }
            }
            cout << ans << '\n';
            for (auto x : a) cout << x << ' ';
            cout << '\n';
      }
}