#include <bits/stdc++.h>

using namespace std;

#ifdef BOI
#include "debug.h"
#else
#define debug(args...)
#endif

int main() {
      ios_base :: sync_with_stdio(0);
      cin.tie(0);

      int n; cin >> n;
      string s; cin >> s;

      int mx = -1;
      for (int i = 0; i + 1 < n; ++i) {
            set <char> sx, sy;
            string f = s.substr(0, i + 1);
            debug(f);
            for (char c : f) sx.insert(c);
            f = s.substr(i + 1, n - i - 1);
            debug(f);
            for (char c : f) sy.insert(c);
            set <char> :: iterator it = sx.begin(), it1 = sy.begin();
            int cnt = 0;
            while (3) {
                  if (it == sx.end() || it1 == sy.end()) break;
                  if (*it == *it1) ++cnt, ++it, ++it1;
                  else if (*it > *it1) ++it1;
                  else ++it;
            }
            mx = max(mx, cnt);
      }      

      cout << mx << endl;
}
