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

      double h; cin >> h;
      cout << fixed << setprecision(10) << '\n';
      cout << sqrt(h * (12800000.0 + h)) << '\n';
}