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
            vector <int> a(n);
            for (int &x : a) cin >> x;
            // a[j] - j = a[i] - i
            for (int i = 0; i < n; ++i) a[i] -= i + 1;
            map <int, int64_t> cnt;
            for (int i = 0; i < n; ++i) cnt[a[i]]++;
 
            int64_t ans = 0;
            for (auto [x, y] : cnt) {
                  ans += (y * (y - 1)) / 2;
            }
 
            cout << ans << '\n';
      }
 
      #ifdef Icry
            auto end = chrono :: high_resolution_clock :: now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << chrono :: duration_cast <chrono :: duration <double>> (end - begin).count() << " seconds]\n";  
      #endif
}