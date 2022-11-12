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
            int n, s; cin >> n >> s;
            vector <int> a(n); for (int &x : a) cin >> x;
            int tot = accumulate(a.begin(), a.end(), 0);
            if (tot == s) cout << "0\n";
            else if (s > tot) cout << "-1\n";
            else {
                  vector <int> p(n), su(n);
                  p[0] = a[0];
                  for (int i = 1; i < n; ++i) p[i] = p[i - 1] + a[i];
                  su[n - 1] = a[n - 1];
                  for (int i = n - 2; i >= 0; --i) su[i] = su[i + 1] + a[i];
                  vector <int> lst(n + 1, -1);
                  for (int i = n - 1; i >= 0; --i) if (lst[su[i]] == -1) lst[su[i]] = i;
                  int ans = INT_MAX;
                  for (int i = 0; i < n; ++i) {
                        int have = tot - p[i];
                        if (have == s) ans = min(ans, i + 1);
                        else if (have > s) {
                              int d = have - s;
                              int id = lst[d];
                              if (id != -1 && id > i) {
                                    ans = min(ans, i + 1 + n - id);
                              }
                        }
                        have = p[i];
                        if (have == s) ans = min(ans, n - 1 - i);
                  }
                  if (ans == INT_MAX) cout << "-1\n";
                  else cout << ans << '\n';
            }
      }
}