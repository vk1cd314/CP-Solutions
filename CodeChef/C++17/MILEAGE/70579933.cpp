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
            int n, x, y, a, b; cin >> n >> x >> y >> a >> b;
            if (n * x * b == n * y * a) cout << "ANY\n";
            else if (n * x * b < n * y * a) cout << "PETROL\n";
            else cout << "DIESEL\n";
      }
}