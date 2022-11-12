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

      int a, b, c; cin >> a >> b >> c;
      bool ok = false;

      for (int i = 0; i < b; ++i) {
            if ((a % b) * i % b == c) ok = true;
      }   

      cout << (ok ? "YES" : "NO");
}
