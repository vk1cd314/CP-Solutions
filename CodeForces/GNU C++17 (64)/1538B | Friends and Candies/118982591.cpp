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
            vector <int64_t> a(n); for (auto &x : a) cin >> x;
            int64_t sum = accumulate(a.begin(), a.end(), 0LL);
 
            if (sum % n) {
                  cout << "-1\n";
                  continue;
            }
 
            int64_t req = sum / n;
            int ans = 0;
            debug(req);
            for (int i = 0; i < n; ++i) {
                  if (a[i] != req && a[i] > req) ++ans;
            }
 
            cout << ans << '\n';
      }
 
      #ifdef Icry
            auto end = chrono :: high_resolution_clock :: now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << chrono :: duration_cast <chrono :: duration <double>> (end - begin).count() << " seconds]\n";  
      #endif
}