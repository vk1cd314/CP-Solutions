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

      string s; cin >> s;
      string tmp = s;
      reverse(tmp.begin(), tmp.end());
      bool ok = false;
      for (int i = 0; i <= 7; ++i) {
            for (int j = 0; j <= 7; ++j) {
                  if (i + j == 7) {
                        string shuru = s.substr(0, i);
                        string shesh = tmp.substr(0, j);
                        reverse(shesh.begin(), shesh.end());
                        string now = shuru + shesh;
                        if (now == "keyence") {
                              ok = true;
                              break;
                        }
                  }
            }
            if (ok) break;
      }

      cout << (ok ? "YES" : "NO");
}
