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
            if ((s.back() - '0') % 2 == 0) cout << "0\n";
            else {
                  int ss = -1;
                  for (int i = 0; i < (int) s.size(); ++i) {
                        if ((s[i] - '0') % 2 == 0) {
                              ss = i;
                              break;
                        }
                  }
                  if (ss == -1) cout << "-1\n";
                  else if (ss == 0) cout << "1\n";
                  else cout << "2\n";
            }
      } 
}