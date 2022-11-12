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
 
      set <int64_t> ded;
      int64_t curr = 1;
      while (curr * curr < (int64_t) 1e10) ded.insert(2LL * curr * curr), curr++;
 
      curr = 2;
      while (curr * curr < (int64_t) 1e10) ded.insert(curr * curr), curr += 2;
 
      int t; cin >> t;
      while (t--) {
            int64_t n; cin >> n;
            if (ded.count(n)) cout << "YES\n";
            else cout << "NO\n";
      }
 
      #ifdef Icry
            auto end = chrono :: high_resolution_clock :: now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << chrono :: duration_cast <chrono :: duration <double>> (end - begin).count() << " seconds]\n";  
      #endif
}