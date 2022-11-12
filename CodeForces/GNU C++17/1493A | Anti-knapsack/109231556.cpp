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
            int n, k; cin >> n >> k;
            set <int> ff;
            for (int i = 1; i <= n; ++i) ff.insert(i);
            ff.erase(k);
            debug(ff);
            for (int i = 1; i < k; ++i) {
                  if (ff.count(i) && ff.count(k - i) && i != k - i) {
                        ff.erase(i);
                        debug(i, k - i);
                        debug(ff);
                  }
            }
            cout << ff.size() << '\n';
            for (int x : ff) cout << x << ' ';
            cout << '\n';
      }
 
      #ifdef Icry
            auto end = std::chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << std::chrono::duration_cast <std::chrono::duration <double>>(end - begin).count() << " seconds]\n";  
      #endif
}