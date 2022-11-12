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

      int x, y; cin >> x >> y;

	  cout << (abs(x - y) < 3 ? "Yes\n" : "No\n");
}
