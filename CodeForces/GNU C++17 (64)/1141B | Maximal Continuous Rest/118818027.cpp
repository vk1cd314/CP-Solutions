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
 
      int n; cin >> n;
      vector <int> a(n); for (int &x : a) cin >> x;
      
      vector <pair <int, int>> segs;
      segs.push_back({a[0], 1});
      
      int ans = 0;
      if (segs.back().first == 1) ans = max(ans, segs.back().second);
      for (int i = 1; i < n; ++i) {
            if (a[i] == segs.back().first) segs.back().second++;
            else {
                  segs.push_back({a[i], 1});
            }
            if (segs.back().first == 1) ans = max(ans, segs.back().second);
      }
 
      if ((int) segs.size() > 2 && segs[0].first == 1 && segs.back().first == 1) {
            ans = max(segs[0].second + segs.back().second, ans);
      }
 
      cout << ans << '\n';
 
      #ifdef Icry
            auto end = chrono :: high_resolution_clock :: now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << chrono :: duration_cast <chrono :: duration <double>> (end - begin).count() << " seconds]\n";  
      #endif
}