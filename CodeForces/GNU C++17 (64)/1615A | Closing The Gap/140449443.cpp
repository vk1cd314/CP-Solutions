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
            int n; cin >> n;
            int sum = 0;
            for (int i = 0; i < n; ++i) {
                  int x; cin >> x;  
                  sum += x;
            }
            if (sum % n) cout << 1 << '\n';
            else cout << 0 << '\n';
      }
}