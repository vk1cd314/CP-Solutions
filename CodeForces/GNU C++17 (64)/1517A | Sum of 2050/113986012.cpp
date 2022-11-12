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
 
 
      vector <int64_t> a;
      int64_t curr = 2050;
      int64_t big = (int64_t) 1e18;
      while (curr < big) a.push_back(curr), curr *= 10LL;
 
      int t; cin >> t;
      while (t--) {
            int64_t n; cin >> n;
            int cnt = 0;
            for (int i = (int) a.size() - 1; i >= 0; --i) {
                  while (n - a[i] >= 0) n -= a[i], ++cnt;
            }
            if (n) cout << "-1\n";
            else cout << cnt << '\n';
      }
 
      #ifdef Icry
            auto end = chrono :: high_resolution_clock :: now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << chrono :: duration_cast <chrono :: duration <double>> (end - begin).count() << " seconds]\n";  
      #endif
}