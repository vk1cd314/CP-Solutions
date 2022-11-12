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
      // ios_base :: sync_with_stdio(0);
      // cin.tie(0);
 
      int n, t; cin >> n >> t;
      int k; cin >> k;
      int l = 1, r = n;
 
      auto query = [&](int l, int r) {
            cout << "? " << l << ' ' << r << endl;
            int sum; cin >> sum;
            return sum;
      };
 
      while (l < r) {
            int mid = l + r >> 1;
            int qq = query(1, mid);
            if (mid - qq < k) l = mid + 1;
            else r = mid;
      }
      cout << "! " << l << endl;
 
      #ifdef Icry
            auto end = chrono :: high_resolution_clock :: now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << chrono :: duration_cast <chrono :: duration <double>> (end - begin).count() << " seconds]\n";  
      #endif
}