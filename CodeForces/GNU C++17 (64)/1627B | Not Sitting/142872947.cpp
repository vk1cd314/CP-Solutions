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
            int n, m; cin >> n >> m;
            vector <int> aa;
            for (int i = 0; i < n; ++i) {
                  for (int j = 0; j < m; ++j) {
                        aa.push_back(max(i, n - 1 - i) + max(j, m - 1 - j));
                  }
            }
            sort(aa.begin(), aa.end());
            for (int x : aa) cout << x << ' ';
            cout << '\n';
      }
}