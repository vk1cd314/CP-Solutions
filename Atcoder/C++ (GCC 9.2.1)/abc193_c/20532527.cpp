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

      int64_t n; cin >> n;
      // int64_t cnt = 0;
      map <int64_t, bool> dd;
      for (int64_t i = 2; i * i <= n; ++i) {
            int64_t val = i;
            while (val * i <= n) val *= i, dd[val] = true;
            // debug(val);
      }
      cout << n - (int) dd.size() << '\n';

      #ifdef Icry
            auto end = std::chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << std::chrono::duration_cast <std::chrono::duration <double>>(end - begin).count() << " seconds]\n";  
      #endif
}