#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
using namespace std;
 
const int N = 43;
int dp[N][N][N][N], n, a, b, mn;
string x;
 
int rec(int i, int r, int g, int rc) {
      if (i == n) {
            if (rc && rc != n && !r && !g) return abs(2 * rc - n);
            return N + 10;
      }
      int &ret = dp[i][r][g][rc];
      if (~ret) return ret;
 
      ret = N + 10;
      ret = min(ret, rec(i + 1, (r * 10 + x[i] - '0') % a, g, rc + 1));
      ret = min(ret, rec(i + 1, r, (g * 10 + x[i] - '0') % b, rc));
 
      return ret;
}
 
void print(int i, int r, int g, int rc) {
      if (i == n) {
            cout << '\n';
            return;
      }
      if (rec(i + 1, (r * 10 + x[i] - '0') % a, g, rc + 1) == mn) {
            cout << "R";
            print(i + 1, (r * 10 + x[i] - '0') % a, g, rc + 1);
      } else {
            cout << "B";
            print(i + 1, r, (g * 10 + x[i] - '0') % b, rc);
      }
}
 
int main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
 
      int t; cin >> t;
      while (t--) {
            cin >> n >> a >> b >> x;
            memset(dp, -1, sizeof dp);
            mn = rec(0, 0, 0, 0);
            if (mn >= N + 10) {
                  cout << "-1\n";
                  continue;
            }
            print(0, 0, 0, 0);
      }
}