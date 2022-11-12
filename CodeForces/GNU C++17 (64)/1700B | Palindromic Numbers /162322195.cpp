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
            if (s[0] != '9') {
                  for (char c : s) {
                        int d = c - '0';
                        cout << 9 - d;
                  }
                  cout << '\n';
            } else {
                  string res(n, '#');
                  int c = 0;
                  for (int i = n - 1; i >= 0; --i) {
                        int d = s[i] - '0';
                        d += c;
                        if (d < 2) {
                              if (!d) res[i] = '1';
                              else res[i] = '0';
                              c = 0;
                        } else res[i] = char('0' + 11 - d), c = 1;
                  }
                  cout << res << '\n';
            }
      }
}