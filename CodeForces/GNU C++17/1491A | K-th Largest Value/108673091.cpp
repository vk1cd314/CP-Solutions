#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
using namespace std;
 
int main() {
      #ifdef Icry
            auto begin = std::chrono::high_resolution_clock::now();
      #endif
      ios_base :: sync_with_stdio(0);
      cin.tie(0);
 
      int n, q; cin >> n >> q;
      int c0 = 0, c1 = 0;
      vector <int> a(n); for (int &x : a) cin >> x, c0 += (x == 0);
      c1 = n - c0;
 
      debug(c0, c1);
      while (q--) {
            int t; cin >> t;
            if (t == 1) {
                  int x; cin >> x;
                  --x;
                  if (a[x] == 1) a[x] = 0, --c1, ++c0;
                  else a[x] = 1, ++c1, --c0;
            } else {
                  int k; cin >> k;
                  if (k > c1) cout << "0\n";
                  else cout << "1\n";
            }
      }
 
      #ifdef Icry
            auto end = std::chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << std::chrono::duration_cast <std::chrono::duration <double>>(end - begin).count() << " seconds]\n";  
      #endif
}