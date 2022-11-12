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
      
      int n, x; cin >> n >> x;
      string s; cin >> s;

      for (char c : s) {
            if (c == 'o') ++x;
            else x = max(0, x - 1);
      }

      cout << x << endl;
}
