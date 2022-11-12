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
 
      int n; cin >> n;
      map <int, int> lst;
      vector <int> c(n); for (int &x : c) cin >> x, lst[x] = -1;
      for (auto &[x, y] : lst) {
            int i = n - 1;
            while (i >= 0 && c[i] == x) --i;
            y = i;
      }
 
      int ans = 0;
      for (int i = 0; i < n; ++i) {
            ans = max(ans, lst[c[i]] - i);
      }
 
      cout << ans << '\n';
      
      #ifdef Icry
            auto end = std::chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << std::chrono::duration_cast <std::chrono::duration <double>>(end - begin).count() << " seconds]\n";  
      #endif
}