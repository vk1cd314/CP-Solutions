#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
using namespace std;
 
const int N = 1e6 + 10;
int f[N];
 
int main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
 
      int n; cin >> n;
      for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            f[x]++;
      }
 
      int ans = 0;
      for (int i = 1; i < N; ++i) {
            int g = 0;
            for (int j = i; j < N; j += i) {
                  if (f[j]) g = __gcd(g, j);
            }
            if (g == i) ans++;
      }
 
      cout << ans - n << '\n';
}