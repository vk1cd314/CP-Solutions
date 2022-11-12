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
            int x; cin >> x;
            if (n == 1) {
                  cout << "1\n";
                  continue;
            }
            // 2 4 6 8 1 ext 
            bool found = false;
            vector <int> ans;
            for (int i = 1; i <= n && !found; ++i) {
                  // 1 at i
                  int lft = i - 1, rgt = n - i + 1;
                  for (int num = 2; num <= n; ++num) {
                        if (n / num < lft) continue;
                        int have = lft;
                        long long tot = have * num + rgt;
                        if (tot == x) {
                              debug(i, num, tot);
                              vector <int> done(n + 1);
                              for (int k = 1; k <= have; ++k) {
                                    ans.push_back(k * num);
                                    done[k * num] = 1;
                              }
                              ans.push_back(1); done[1] = 1;
                              for (int k = 1; k <= n; ++k) {
                                    if (!done[k]) ans.push_back(k);
                              }
                              found = true;
                              break;
                        }
                  }
            }
            if (!found) cout << "-1\n";
            else {
                  int ff = 0, tot = 0;
                  for (int xx : ans) ff = __gcd(ff, xx), tot += ff;
                  debug(tot);
                  assert(tot == x);
                  for (int xx : ans) cout << xx << ' ';
                  cout << '\n';
            } 
      }
}
// 4 6
// 3 1 2 4