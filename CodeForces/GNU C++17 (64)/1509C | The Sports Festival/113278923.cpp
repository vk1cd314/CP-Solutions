#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
using namespace std;
 
const int N = 2e3 + 10;
int64_t dp[N][N], a[N];
 
int64_t rec(int i, int j) {
      if (i > j) return 0;
      int64_t &ret = dp[i][j];
      if (~ret) return ret;
 
      ret = min(rec(i + 1, j), rec(i, j - 1)) + a[j] - a[i];
      return ret;
}
 
int main() {
      #ifdef Icry
            auto begin = chrono :: high_resolution_clock :: now();
      #endif
      ios_base :: sync_with_stdio(0);
      cin.tie(0);
 
      int n; cin >> n;
      for (int i = 0; i < n; ++i) cin >> a[i];
      sort(a, a + n);
      memset(dp, -1, sizeof dp);
      cout << rec(0, n - 1) << '\n';
 
      #ifdef Icry
            auto end = chrono :: high_resolution_clock :: now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << chrono :: duration_cast <chrono :: duration <double>> (end - begin).count() << " seconds]\n";  
      #endif
}