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
            vector <int64_t> b(n + 2); for (auto &x : b) cin >> x;
            sort(b.begin(), b.end());
 
            int64_t pre = 0;
            for (int i = 0; i < n; ++i) pre += b[i];
            debug(pre, b);
            if (pre == b[n]) {
                  for (int i = 0; i < n; ++i) cout << b[i] << ' ';
                  cout << '\n';
                  continue;
            }
 
            if (pre == b[n + 1]) {
                  swap(b[n], b[n + 1]);
                  for (int i = 0; i < n; ++i) cout << b[i] << ' ';
                  cout << '\n';
                  continue;
            }
 
            pre += b[n];
            bool ok = false;
            for (int i = 0; i < n; ++i) {
                  if (pre - b[i] == b[n + 1]) {
                        swap(b[i], b[n]);
                        swap(b[n + 1], b[n]);
                        ok = true;
                        break;
                  }
            }
 
            if (!ok) cout << "-1\n";
            else {
                  for (int i = 0; i < n; ++i) cout << b[i] << ' ';
                  cout << '\n'; 
            }
      }
 
      #ifdef Icry
            auto end = std::chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << std::chrono::duration_cast <std::chrono::duration <double>>(end - begin).count() << " seconds]\n";  
      #endif
}