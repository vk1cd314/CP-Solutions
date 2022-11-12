#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
using namespace std;
 
const int N = 5002;
int64_t a[N], b[N];
 
int main() {
      #ifdef Icry
            auto begin = chrono :: high_resolution_clock :: now();
      #endif
      ios_base :: sync_with_stdio(0);
      cin.tie(0);
 
      int n; cin >> n;
      for (int i = 0; i < n; ++i) cin >> a[i];
      for (int i = 0; i < n; ++i) cin >> b[i];
 
      int64_t ans = 0;
      for (int i = 0; i < n; ++i) ans = (ans + a[i] * b[i]);
      
      int64_t maxChange = 0;
      for (int i = 0; i < n; ++i) {
            int l = i, r = i;
            int64_t change = 0;
            while (l >= 0 && r < n) {
                  change += a[r] * b[l] + a[l] * b[r];
                  change -= a[l] * b[l] + a[r] * b[r];
                  maxChange = max(maxChange, change);
                  --l, ++r;
            }
            l = i - 1, r = i;
            if (l < 0) continue;
            change = 0;
            while (l >= 0 && r < n) {
                  change += a[r] * b[l] + a[l] * b[r];
                  change -= a[l] * b[l] + a[r] * b[r];
                  maxChange = max(maxChange, change);
                  --l, ++r;
            }
      }
 
      cout << maxChange + ans << '\n';
 
 
      #ifdef Icry
            auto end = chrono :: high_resolution_clock :: now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << chrono :: duration_cast <chrono :: duration <double>> (end - begin).count() << " seconds]\n";  
      #endif
}