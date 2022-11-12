#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
using namespace std;
 
int main() {
      #ifdef Icry
            auto begin = chrono :: high_resolution_clock :: now();
      #endif
      ios_base :: sync_with_stdio(0);
      cin.tie(0);
 
      int t; cin >> t;
      while (t--) {
            int n; cin >> n;
            int xr = 0;
            vector <int64_t> a(n); for (auto &x : a) cin >> x, xr ^= x;
            
            if (!xr) {
                  cout << "YES\n";
                  continue;
            }
 
            vector <int> pre(n);
            pre[0] = a[0];
            for (int i = 1; i < n; ++i) pre[i] = pre[i - 1] ^ a[i];
            bool ok = false;
            for (int i = 0; i < n && !ok; ++i) {
                  for (int j = i + 1; j + 1 < n && !ok; ++j) {
                        int seg1 = pre[i];
                        int seg2 = pre[j] ^ pre[i];
                        int seg3 = pre[n - 1] ^ pre[j];
                        if (seg1 == seg2 && seg1 == seg3) ok = true;
                  } 
            }
 
            cout << (ok ? "YES\n" : "NO\n");
      }
 
      #ifdef Icry
            auto end = chrono :: high_resolution_clock :: now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << chrono :: duration_cast <chrono :: duration <double>> (end - begin).count() << " seconds]\n";  
      #endif
}