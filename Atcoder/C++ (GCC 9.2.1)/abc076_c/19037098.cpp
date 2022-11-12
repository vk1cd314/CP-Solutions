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

      string s, t; cin >> s >> t;
      reverse(s.begin(), s.end());
      reverse(t.begin(), t.end());

      debug(s, t);
      int sz = s.size(), sz1 = t.size();
      bool ok = false;
      for (int i = 0; i < sz - sz1 + 1; ++i) {
            int cnt = 0;
            for (int j = 0; j < sz1; ++j) {
                  if (s[i + j] == t[j] || s[i + j] == '?') ++cnt;
            }
            if (cnt == sz1) {
                  ok = true;
                  for (int j = 0; j < sz1; ++j) {
                        s[i + j] = t[j];
                  }
                  break;
            }
      }      

      if (!ok) cout << "UNRESTORABLE\n";
      else {
            reverse(s.begin(), s.end());
            for (char c : s) cout << (c == '?' ? 'a' : c);
      }
}
