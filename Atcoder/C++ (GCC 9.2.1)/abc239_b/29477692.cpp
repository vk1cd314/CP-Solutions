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

      int64_t x; cin >> x;
      if (x < 0) {
            if (x % 10 == 0) cout << x / 10LL << '\n';
            else {
                  cout << x / 10LL - 1 << '\n';
            }
      } else cout << x / 10LL << '\n';

}