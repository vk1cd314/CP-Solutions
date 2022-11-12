#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif

using namespace std;

const int N = 1e5 + 10;
int dp[111][N], a[111], n, sum = 0;

int go(int i, int t) {
      if (i == n) return max(t, sum - t);

      int &ret = dp[i][t];
      if (~ret) return ret;

      ret = min(go(i + 1, t + a[i]), go(i + 1, t));

      return ret;
}

int main() {
      #ifdef Icry
            auto begin = chrono :: high_resolution_clock :: now();
      #endif
      ios_base :: sync_with_stdio(0);
      cin.tie(0);

      cin >> n;
      for (int i = 0; i < n; ++i) cin >> a[i], sum += a[i];
      // sort(a, a + n);
      // reverse(a, a + n);

      memset(dp, -1, sizeof dp);
      cout << go(0, 0) << '\n';

      #ifdef Icry
            auto end = chrono :: high_resolution_clock :: now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << chrono :: duration_cast <chrono :: duration <double>> (end - begin).count() << " seconds]\n";  
      #endif
}