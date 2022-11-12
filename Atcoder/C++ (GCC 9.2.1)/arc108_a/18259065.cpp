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

      string f = "";
      for (char c : s) {
            f.push_back(c);
            if (f.size() > 2) {
                  int l = f.size();
                  if (f[l - 1] == 'x' && f[l - 2] == 'o' && f[l - 3] == 'f') {
                        f.pop_back();
                        f.pop_back();
                        f.pop_back();
                  }
            }
      }      
      cout << f.size() << endl;
}
