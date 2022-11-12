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
            int n; cin >> n;
            vector <int> M, D;
            for (int i = 0; i < 2 * n; ++i) {
                  int x, y; cin >> x >> y;
                  if (!x) M.push_back(y < 0 ? -y : y);
                  if (!y) D.push_back(x < 0 ? -x : x);
            }
            sort(M.begin(), M.end());
            sort(D.begin(), D.end());
            debug(M, D);
            long double ans = 0;
            
            auto dist = [&](long double x, long double y) {
                  long double ret = x * x + y * y;
                  ret = sqrtl(ret);
                  ans += ret;
            };
 
            for (int i = 0; i < n; ++i) dist(M[i], D[i]);
 
            cout << fixed << setprecision(10);
            cout << ans << '\n';
      } 
 
      #ifdef Icry
            auto end = std::chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << std::chrono::duration_cast <std::chrono::duration <double>>(end - begin).count() << " seconds]\n";  
      #endif
}