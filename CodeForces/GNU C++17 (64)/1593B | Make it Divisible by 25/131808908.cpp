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
            string s; cin >> s;
            // 25 50 75 00
            int ans = INT_MAX;
            vector <int> v = {0, 5};
            for (int x : v) {
                  string tmp = s;
                  // debug(x, tmp);
                  // debug(tmp.back());
                  while (!tmp.empty() && int(tmp.back() - '0') != x) tmp.pop_back();
                  // debug(tmp);
                  if (tmp.empty()) continue;
                  int rem = s.size() - tmp.size();
                  int sz = tmp.size();
                  bool xx = true;
                  for (int i = sz - 2; i >= 0; --i) {
                        if (x == 0) {
                              if (tmp[i] == '0') {
                                    rem += max(0, (sz - 2) - (i + 1) + 1);
                                    xx = false;
                                    break;
                              } else if (tmp[i] == '5') {
                                    // i + 1 to sz - 2
                                    rem += max(0, (sz - 2) - (i + 1) + 1);
                                    xx = false;
                                    break;
                              }
                        } else {
                              if (tmp[i] == '2' || tmp[i] == '7') {
                                    rem += max(0, (sz - 2) - (i + 1) + 1);
                                    xx = false;
                                    break;
                              }
                        }
                  }
                  // debug(tmp, rem);
                  // debug(xx);
                  if (!xx) ans = min(ans, rem);
            }
            if (ans == INT_MAX) {
                  assert(false);
                  debug(s);
            }
            cout << ans << '\n';
      }
}