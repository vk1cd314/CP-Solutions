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
            set <char> ss;
            int n = s.size();
            int ans = 0;
            for (int i = 0; i < n; ++i) {
                  if (ss.size() <= 3) {
                        ss.insert(s[i]);
                  } 
                  if (ss.size() > 3) {
                        ss.clear();
                        ++ans;
                        ss.insert(s[i]);
                  }
            }
            if (!ss.empty()) ++ans;
            cout << ans << '\n';
      }
}