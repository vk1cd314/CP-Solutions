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
      vector <array <int64_t, 3>> v(n);
      for (int i = 0; i <n; ++i) {
            int64_t a, x, p; cin >> a >> x >> p;
            v[i][0] = a;
            v[i][1] = x;
            v[i][2] = p;
      }

      int64_t ans = INT_MAX;
      for (int i = 0; i < n; ++i) {
            int64_t left = 0;
            left = v[i][2] - v[i][0];
            if (left > 0) ans = min(ans, v[i][1]);
      }

      cout << (ans == INT_MAX ? -1 : ans) << '\n';

      #ifdef Icry
            auto end = std::chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << std::chrono::duration_cast <std::chrono::duration <double>>(end - begin).count() << " seconds]\n";  
      #endif
}