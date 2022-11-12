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
            vector <int> b(n), d(n);
            map <int, vector <int>> mp;
            for (int i = 0; i < n; ++i) {
                  cin >> b[i] >> d[i];
                  mp[d[i]].push_back(b[i]);
            }
            bool ok = true;
            for (int i = 1; i <= 10; ++i) {
                  ok &= mp.count(i);
                  debug(mp.count(i));
            }
            debug(mp);
            if (!ok) {
                  cout << "MOREPROBLEMS\n";
                  continue;
            }
            int ans = 0;
            for (int i = 1; i <= 10; ++i) {
                  ans += *max_element(mp[i].begin(), mp[i].end());
            }
            cout << ans << '\n';
 
      }
}