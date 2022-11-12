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
            int n, k; cin >> n >> k;
            auto ispalin = [&](string s) {
                  string t = s;
                  reverse(t.begin(), t.end());
                  return t == s;
            };
            string ss; cin >> ss;
            if (!k) cout << "1\n";
            else {
                  if (ispalin(ss)) cout << "1\n";
                  else cout << "2\n";
            }
      }
}