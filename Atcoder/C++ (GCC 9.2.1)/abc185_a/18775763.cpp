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
      
      int a, b, c, d; cin >> a >> b >> c >> d;
      cout << min({a, b, c, d});
}
