#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif

using namespace std;

int main() {
      #ifdef Icry
            auto begin = chrono :: high_resolution_clock :: now();
      #endif
      ios_base :: sync_with_stdio(0);
      cin.tie(0);

      int n, k; cin >> n >> k;
      int64_t ans = 0;
      for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= k; ++j) {
                  int st = i * 100 + j;
                  ans += 1LL * st;
            }
      }

      cout << ans << '\n';

      #ifdef Icry
            auto end = chrono :: high_resolution_clock :: now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << chrono :: duration_cast <chrono :: duration <double>> (end - begin).count() << " seconds]\n";  
      #endif
}