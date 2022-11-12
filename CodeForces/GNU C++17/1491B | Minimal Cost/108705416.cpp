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
            int64_t u, v; cin >> u >> v;
            vector <int64_t> a(n); for (auto &x : a) cin >> x;
 
            // sort(a.begin(), a.end());
            bool ok = false, ok1 = false;
            for (int i = 1; i < n; ++i) {
                  if (abs(a[i] - a[i - 1]) > 1) {
                        ok = true;
                  }
            }
 
            if (ok) {
                  cout << "0\n";
                  continue;
            }
 
            sort(a.begin(), a.end());
            if (a[0] == a.back()) {
                  cout << min((v << 1), u + v) << '\n';
                  continue;
            } 
            cout << min(u, v) << '\n';
      }
 
      #ifdef Icry
            auto end = std::chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << std::chrono::duration_cast <std::chrono::duration <double>>(end - begin).count() << " seconds]\n";  
      #endif
}