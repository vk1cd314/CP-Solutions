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
      outer: while (t--) {
            int n; cin >> n;
            vector <int> a(n); for (int &x : a) cin >> x;
            int ans = 1;
            for (int i = 0; i < n; ++i) {
                  int sem = 0;
                  vector <int> divs;
                  map <int, int> cnt;
                  for (int j = 0; j < n; ++j) {
                        if (a[i] == a[j]) sem++;
                        else {
                              int x = abs(a[i] - a[j]);
                              for (int k = 1; k * k <= x; ++k) {
                                    if (x % k == 0) {
                                          cnt[k]++;
                                          divs.push_back(k);
                                          if (k != x / k) divs.push_back(x / k), cnt[x / k]++;
                                    }
                              }
                        }
                  }
                  if (sem >= n / 2) {
                        cout << -1 << '\n';
                        goto outer;
                  }
                  for (int x : divs) {
                        if (sem + cnt[x] >= n / 2) {
                              ans = max(ans, x);
                        }
                  }
            }
            cout << ans << '\n';
      }
}