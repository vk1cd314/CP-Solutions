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

      int n; cin >> n;
      string s, t; cin >> s >> t;
      string res(n, '0');
      int hs = 0, ht = 0;
      for (int i = n - 1; i >= 0; --i) {
            if (s[i] == t[i]) res[i] = '0';
            else {
                  hs += (res[i] ^ s[i]);
                  ht += (res[i] ^ t[i]);
            }
      }
      debug(res, hs, ht);
      for (int i = n - 1; i >= 0; --i) {
            if (s[i] == t[i]) continue;
            if (hs > ht) {
                  if (s[i] == '1') {
                        res[i] = s[i];
                        hs--, ht++;
                  }
            } else if (hs < ht) {
                  if (t[i] == '1') {
                        res[i] = t[i];
                        hs++, ht--;
                  }
            }
      }
      if (hs != ht) cout << "-1\n";
      else cout << res << "\n";
}