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
            vector <int> a(2 * n); for (int &x : a) cin >> x;
 
            sort(a.begin(), a.end());
            int l = 0, r = 2 * n - 1;
            for (int i = 0; i < 2 * n; ++i) {
                  if (i & 1 ^ 1) cout << a[l++] << ' ';
                  else cout << a[r--] << ' ';
            }
            cout << '\n';
      }
 
      #ifdef Icry
            auto end = chrono :: high_resolution_clock :: now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << chrono :: duration_cast <chrono :: duration <double>> (end - begin).count() << " seconds]\n";  
      #endif
}