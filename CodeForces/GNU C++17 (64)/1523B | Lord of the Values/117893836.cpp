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
            vector <int> a(n); for (int &x : a) cin >> x;
            cout << 6 * (n / 2) << '\n';
            for (int i = 1; i <= n / 2; ++i) {
                  cout << "2 " << i << ' ' << n / 2 + i << '\n';
                  cout << "1 " << i << ' ' << n / 2 + i << '\n';
                  cout << "2 " << i << ' ' << n / 2 + i << '\n';
                  cout << "1 " << i << ' ' << n / 2 + i << '\n';
                  cout << "2 " << i << ' ' << n / 2 + i << '\n';
                  cout << "1 " << i << ' ' << n / 2 + i << '\n';
            }
      }
 
      #ifdef Icry
            auto end = chrono :: high_resolution_clock :: now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << chrono :: duration_cast <chrono :: duration <double>> (end - begin).count() << " seconds]\n";  
      #endif
}