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
            int n, x; cin >> n >> x;
            vector <int> w(n); for (int &x : w) cin >> x;
            
            int sum = accumulate(w.begin(), w.end(), 0);
            if (sum == x) {
                  cout << "NO\n";
                  continue;
            }
 
            while (true) {
                  bool ok = true;
                  int curr = 0;
                  for (int y : w) {
                        curr += y;
                        if (curr == x) ok = false;
                  }
                  if (ok) break;
                  random_shuffle(w.begin(), w.end());
            }
 
            cout << "YES\n";
            for (int y : w) cout << y << ' ';
            cout << '\n';
      }
 
      #ifdef Icry
            auto end = chrono :: high_resolution_clock :: now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << chrono :: duration_cast <chrono :: duration <double>> (end - begin).count() << " seconds]\n";  
      #endif
}