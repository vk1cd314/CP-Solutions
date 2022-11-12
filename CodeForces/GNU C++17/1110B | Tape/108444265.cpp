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
 
      int n, m, k; cin >> n >> m >> k;
      vector <int> b(n); for (int &x : b) cin >> x;
      vector <int> diffs;
      for (int i = 0; i + 1 < n; ++i) diffs.push_back(b[i + 1] - b[i]);
      sort(diffs.begin(), diffs.end());
 
      int64_t ans = 0;
      for (int i = 0; i < n - k; ++i) {
            ans += diffs[i];
      }
 
      cout << ans + k << '\n';
 
 
      #ifdef Icry
            auto end = std::chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << std::chrono::duration_cast <std::chrono::duration <double>>(end - begin).count() << " seconds]\n";  
      #endif
}