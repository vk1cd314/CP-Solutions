#include <bits/stdc++.h>

using namespace std;

#ifdef BOI
#include "debug.h"
#else
#define debug(args...)
#endif

bool even(string s) {
      int n = s.size();
      string x = s.substr(0, n / 2);
      string y = s.substr(n / 2, n / 2);
      return x == y;
}

int main() {
      ios_base :: sync_with_stdio(0);
      cin.tie(0);
      
      string s; cin >> s;
      int l = 2, ans;
      while (1) {
            if (l >= (int) s.size()) break;

            string f = s.substr(0, (int) s.size() - l);
            debug(f);

            if (even(f)) {
                  ans = (int) s.size() - l;
                  break;
            }
            l += 2;
      }

      cout << ans << endl;
}
