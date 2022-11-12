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
            vector <string> a(8);
            for (auto &x : a) cin >> x;
            pair <int, int> ans = {-1, -1};
            for (int i = 1; i <= 6; ++i) {
                  for (int j = 1; j <= 6; ++j) {
                        if (a[i][j] == '#' && a[i - 1][j - 1] == '#' && a[i + 1][j - 1] == '#'
                                    && a[i - 1][j + 1] == '#' && a[i + 1][j + 1] == '#') {
                                          ans = {i + 1, j + 1};
                                          break;
                                    } 
                  }
            }
            cout << ans.first << ' ' << ans.second << '\n';
      }
}