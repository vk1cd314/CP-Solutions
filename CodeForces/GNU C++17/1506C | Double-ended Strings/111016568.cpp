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
 
      int t; cin >> t;
      while (t--) {
            string a, b; cin >> a >> b;
            int m = a.size(), n = b.size();
            int LCSuff[m + 1][n + 1];
            int result = 0; 
            for (int i = 0; i <= m; i++) {
                  for (int j = 0; j <= n; j++) {
                        if (i == 0 || j == 0) LCSuff[i][j] = 0;
                        else if (a[i - 1] == b[j - 1]) {
                              LCSuff[i][j] = LCSuff[i - 1][j - 1] + 1;
                              result = max(result, LCSuff[i][j]);
                        }
                        else LCSuff[i][j] = 0;
                  }
            }
            debug(result);
            cout << n + m - 2 * result << '\n';
      }
 
      #ifdef Icry
            auto end = std::chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << std::chrono::duration_cast <std::chrono::duration <double>>(end - begin).count() << " seconds]\n";  
      #endif
}