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
 
      int64_t n, k; cin >> n >> k;
      if (k <= (n + 1) / 2) cout << 2 * k - 1 << '\n';
      else cout << 2 * (k - (n + 1) / 2) << '\n';
}