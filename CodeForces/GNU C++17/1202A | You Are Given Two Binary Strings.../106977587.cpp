#include <bits/stdc++.h>
 
using namespace std;
 
#ifdef SENDHELP
#include "debug.h"
#else
#define debug(args...)
#endif
 
int main() {
      #ifdef SENDHELP
            auto begin = std::chrono::high_resolution_clock::now();
      #endif
      ios_base :: sync_with_stdio(0);
      cin.tie(0);
 
      int t; cin >> t;
      while (t--) {
            string x, y; cin >> x >> y;
            reverse(x.begin(), x.end());
            reverse(y.begin(), y.end());
            int first;
            for (int i = 0; i < y.size(); ++i) {
                  if (y[i] == '1') {
                        first = i;
                        break;
                  }
            }
 
            int ans = -1;
            for (int i = first; i < x.size(); ++i) {
                  if (x[i] == '1') {
                        ans = i - first;
                        break;
                  }
            }
            
            assert(ans != -1);
            cout << ans << '\n';
      }
 
      #ifdef SENDHELP
            auto end = std::chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << std::chrono::duration_cast <std::chrono::duration <double>>(end - begin).count() << " seconds]\n";
      #endif
}