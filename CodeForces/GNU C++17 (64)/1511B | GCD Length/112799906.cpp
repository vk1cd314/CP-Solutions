#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
using namespace std;
 
int64_t digcount(int64_t n) {
      int ret = 0;
      while (n) {
            ret++;
            n /= 10;
      }
      return ret;
}
 
int main() {
      #ifdef Icry
            auto begin = std::chrono::high_resolution_clock::now();
      #endif
      ios_base :: sync_with_stdio(0);
      cin.tie(0);
 
      int t; cin >> t;
      while (t--) {
            int64_t a, b, c; cin >> a >> b >> c;
            int64_t x = 1, y = 1;
            for (int i = 0; i < c - 1; ++i) x *= 10LL, y *= 10LL;
            while (digcount(x) != a) x *= 9LL;
            while (digcount(y) != b) y *= 7LL;
            cout << x << ' ' << y << '\n';
      }
 
      #ifdef Icry
            auto end = std::chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << std::chrono::duration_cast <std::chrono::duration <double>>(end - begin).count() << " seconds]\n";  
      #endif
}