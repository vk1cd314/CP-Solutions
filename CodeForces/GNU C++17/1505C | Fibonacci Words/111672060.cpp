#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
using namespace std;
 
int main() {
      #ifdef Icry
            auto begin = std::chrono::high_resolution_clock::now();
      #endif
      ios_base :: sync_with_stdio(0);
      cin.tie(0);
 
      string s; cin >> s;
      if ((int) s.size() <= 2) {
            cout << "YES\n";
            return 0;
      }
      int st0 = s[0] - 'A', st1 = s[1] - 'A';
      bool ok = true;
      for (int i = 2; i < (int) s.size(); ++i) {
            debug((int)s[i], (st0 + st1) % 26 + 'A');
            if (s[i] != (st0 + st1) % 26 + 'A') ok = false;
            st0 = st1;
            st1 = s[i] - 'A';
      }
 
      cout << (ok ? "YES\n" : "NO\n");
 
      #ifdef Icry
            auto end = std::chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << std::chrono::duration_cast <std::chrono::duration <double>>(end - begin).count() << " seconds]\n";  
      #endif
}