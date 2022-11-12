#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
using namespace std;
 
int main() {
      #ifdef Icry
            auto begin = chrono::high_resolution_clock::now();
      #endif
      ios_base::sync_with_stdio(0);
      cin.tie(0);
 
      int t; cin >> t;
      while (t--) {
            int64_t a, b; cin >> a >> b;
            if (a > b) swap(a, b);
            if (a == b) cout << "0 0\n";
            else if (b - a == 1) cout << "1 0\n";
            else {
                  int64_t diff = b - a;
                  int64_t f1 = (a / diff) * diff;
                  int64_t f2 = ((a + diff - 1) / diff) * diff;
                  int64_t mn = min(abs(f1 - a), abs(f2 - a));
                  cout << b - a << ' ' << mn << '\n';
            }
      }
 
      #ifdef Icry
            auto end = chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << chrono::duration_cast <chrono :: duration <double>> (end - begin).count() << " seconds]\n";  
      #endif
}