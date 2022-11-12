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

      int n, m, x, t, d; cin >> n >> m >> x >> t >> d;
      if (x <= m && m <= n) cout << t << '\n';
      else cout << t - d * (x - m) << '\n';
}