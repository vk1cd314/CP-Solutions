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
 
      int t; cin >> t;
      while (t--) {
            long long n; cin >> n;
 
            while (n % 2 == 0) n /= 2;
 
            if ((n % 2 == 1) && n != 1) cout << "YES\n";
            else cout << "NO\n";
      }      
}
 