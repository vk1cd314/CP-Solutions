#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif

using namespace std;

const int N = 3010;
bitset <N> g[N];

int main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);

      int n; cin >> n;
      for (int i = 0; i < n; ++i) {
            string s; cin >> s;
            for (int j = 0; j < n; ++j) {
                  if (s[j] == '1') g[i][j] = 1;
            }
      }

      long long ans = 0;
      for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                  if (!g[i][j]) continue;
                  ans += (g[i] & g[j]).count();
            }
      }
      ans /= 3;
      cout << ans << '\n';
}