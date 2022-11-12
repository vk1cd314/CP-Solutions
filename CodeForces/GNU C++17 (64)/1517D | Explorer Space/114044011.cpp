#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
using namespace std;
 
const int N = 510;
map <pair <int, int>, int> cost, cost1;
int dp[N][N][30];
int n, m, k;
int ans = INT_MAX;
 
int rec(int i, int j, int l) {
      if (l == k / 2) return 0;
 
      int &ret = dp[i][j][l];
      if (~ret) return ret;
 
      ret = INT_MAX;
      if (i + 1 < n) ret = min(ret, rec(i + 1, j, l + 1) + cost1[{i, j}]);
      if (j + 1 < m) ret = min(ret, rec(i, j + 1, l + 1) + cost[{i, j}]);
      if (i - 1 >= 0) ret = min(ret, rec(i - 1, j, l + 1) + cost1[{i - 1, j}]);
      if (j - 1 >= 0) ret = min(ret, rec(i, j - 1, l + 1) + cost[{i, j - 1}]);
 
      return ret;
}
 
int main() {
      #ifdef Icry
            auto begin = chrono :: high_resolution_clock :: now();
      #endif
      ios_base :: sync_with_stdio(0);
      cin.tie(0);
 
      cin >> n >> m >> k;
      for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m - 1; ++j) {
                  int cc; cin >> cc;
                  cost[{i, j}] = cc;
                  // cost[{i, j + 1}] = cc;
            }
      }
 
      for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < m; ++j) {
                  int cc; cin >> cc;
                  cost1[{i, j}] = cc;
                  // cost1[{i + 1, j}] = cc;
            }
      }
 
      if (k & 1) {
            for (int i = 0; i < n; ++i) {
                  for (int j = 0; j < m; ++j) {
                        cout << "-1 ";
                  }
                  cout << '\n';
            }
      } else {
            memset(dp, -1, sizeof dp);
            for (int i = 0; i < n; ++i) {
                  for (int j = 0; j < m; ++j) {
                        ans = rec(i, j, 0);
                        cout << 2 * ans << ' ';
                  }
                  cout << '\n';
            }
      }
 
      #ifdef Icry
            auto end = chrono :: high_resolution_clock :: now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << chrono :: duration_cast <chrono :: duration <double>> (end - begin).count() << " seconds]\n";  
      #endif
}