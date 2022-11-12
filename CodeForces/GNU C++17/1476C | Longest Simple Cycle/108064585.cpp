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
            int n; cin >> n;
            vector <int64_t> c(n); for (auto &x : c) cin >> x;
            vector <int64_t> a(n); for (auto &x : a) cin >> x;
            vector <int64_t> b(n); for (auto &x : b) cin >> x;
 
            vector <int64_t> F(n);
            F[0] = 0;
 
            for (int i = 1; i < n; ++i) {
                  F[i] = c[i] - 1 + 2 + abs(a[i] - b[i]); // I can either end here 
                  if (a[i] != b[i]) F[i] = max(F[i], c[i] - 1 + 2 + F[i - 1] - abs(a[i] - b[i])); // or continue
            }
 
            cout << *max_element(F.begin(), F.end()) << '\n';
      }
 
      #ifdef SENDHELP
            auto end = std::chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << std::chrono::duration_cast <std::chrono::duration <double>>(end - begin).count() << " seconds]\n";  
      #endif
}