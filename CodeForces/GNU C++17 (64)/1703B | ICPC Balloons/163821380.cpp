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
            string s; cin >> s;
            set <char> ss;
            int ans = 0;
            for (char c : s) {
                  if (!ss.count(c)) ans += 2;
                  else ans++;
                  ss.insert(c);
            }
            cout << ans << '\n';
      }
}