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
            int64_t a, b, c; cin >> a >> b >> c;
            cout << max(0LL, (long long)max(b, c) - a + 1) << ' ';
            cout << max(0LL, (long long)max(a, c) - b + 1) << ' ';
            cout << max(0LL, (long long)max(a, b) - c + 1) << '\n';
      }
}