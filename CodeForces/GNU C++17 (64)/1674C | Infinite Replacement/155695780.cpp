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
            string s, t; cin >> s >> t;
            int ct = count(t.begin(), t.end(), 'a');
            if (ct && (int) t.size() > 1) cout << "-1\n";
            else {
                  if (t == "a") cout << "1\n";
                  else {
                        int64_t ans = 1;
                        for (int i = 0; i < (int) s.size(); ++i) ans <<= 1LL;
                        cout << ans << '\n';
                  }
                  
            }
      }
}