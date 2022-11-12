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
            int ans = INT_MAX;
            pair <int, int> x, y, f; cin >> x.first >> x.second >> y.first >> y.second >> f.first >> f.second;
            if (x.first == y.first && y.first == f.first && (min(x.second, y.second) <= f.second && f.second <= max(x.second, y.second))) ans = min(ans, abs(x.first - y.first) + abs(x.second - y.second) + 2);
            else if (x.second == y.second && y.second == f.second && (min(x.first, y.first) <= f.first && f.first <= max(x.first, y.first))) ans = min(ans, abs(x.first - y.first) + abs(x.second - y.second) + 2);
            else ans = min(ans, abs(x.first - y.first) + abs(x.second - y.second));
 
            cout << ans << '\n';
      }
 
      #ifdef Icry
            auto end = chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << chrono::duration_cast <chrono :: duration <double>> (end - begin).count() << " seconds]\n";  
      #endif
}