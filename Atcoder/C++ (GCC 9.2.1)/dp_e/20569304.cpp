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

      const int N = 1e5 + 33, mx = 0x3f3f3f3f;
      int F[N], W[N], V[N];
      memset(F, 0x3f3f3f3f, sizeof F);
      int n, w; cin >> n >> w;

      for (int i = 0; i < n; ++i) cin >> W[i] >> V[i];

      F[0] = 0;
      for (int i = 0; i < n; ++i) {
            for (int j = N - V[i]; j >= 0; --j) {
                  F[j + V[i]] = min(F[j + V[i]], F[j] + W[i]);
            }
      }

      int ans = 0;
      for (int i = N - 1; i >= 0; --i) {
            if (F[i] <= w) {
                  debug(i);
                  ans = i;
                  debug(F[i]);
                  break;
            }
      }

      cout << ans << '\n';

      #ifdef Icry
            auto end = std::chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << std::chrono::duration_cast <std::chrono::duration <double>>(end - begin).count() << " seconds]\n";  
      #endif
}