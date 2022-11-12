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
            int a, b, c, d; cin >> a >> b >> c >> d;
            if (a - c == b - d) cout << "Any\n";
            else if (a - c < b - d) cout << "First\n";
            else cout << "Second\n";
      }
}