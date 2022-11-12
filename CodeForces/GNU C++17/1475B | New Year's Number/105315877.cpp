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
            int n; cin >> n;
            bool ok = false;
            for (int i = 0; i <= (n + 2020) / 2021; ++i) {
                  if (n - i * 2021 < 0) break;
                  if ((n - i * 2021) % 2020 == 0) {
                        ok = true;
                        break;
                  }
            }
 
            cout << (ok ? "YES\n" : "NO\n");
      }      
}