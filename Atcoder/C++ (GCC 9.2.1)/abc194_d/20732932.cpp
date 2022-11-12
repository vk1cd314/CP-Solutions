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
      vector <double> F(n + 1, 0);
      for (int i = 1; i <= n; ++i) {
            F[i] = F[i - 1] + double(n) / double(i);
      }
      cout << fixed << setprecision(9) << F[n] - 1 << '\n';

      #ifdef Icry
            auto end = std::chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << std::chrono::duration_cast <std::chrono::duration <double>>(end - begin).count() << " seconds]\n";  
      #endif
}