#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
using namespace std;
 
const int N = 2e5 + 10;
int p[N][21];
 
int main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
 
      p[1][0] = 1;
      for (int i = 2; i < N; ++i) {
            for (int j = 0; j < 21; ++j) {
                  p[i][j] += p[i - 1][j];
                  if (i & (1 << j)) p[i][j]++;
            }
      }
 
      int t; cin >> t;
      while (t--) {
            int l, r; cin >> l >> r;
            int ans = INT_MAX, rng = r - l + 1;            
            for (int i = 0; i < 21; ++i) {
                  int have = p[r][i] - p[l - 1][i];
                  ans = min(ans, rng - have);
            }
            cout << ans << '\n';
      }
}