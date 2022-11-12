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
            int n, r, b; cin >> n >> r >> b;
            int ext = r - b - 1;
            vector <string> vv(2 * b + 1);
            for (int i = 0; i < 2 * b + 1; ++i) {
                  if (i & 1) vv[i] = string(1, 'B');
                  else vv[i] = string(1, 'R');
            }
            int redpos = 0;
            while (ext) {
                  vv[redpos].push_back('R');
                  redpos = redpos + 2;
                  if (redpos >= 2 * b + 1) redpos = 0;
                  --ext;
            }
            for (auto s : vv) cout << s;
            cout << '\n';
      }
}