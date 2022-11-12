#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
using namespace std;
 
#define ll long long
 
const int N = 2e7 + 10;
int spf[N], cnt[N];
 
void sieve() {      
      for (int i = 2; i < N; ++i) {
            if (!spf[i]) {
                  for (int j = i; j < N; j += i) {
                        spf[j] = i;
                  }
            }
      }
      for (int i = 2; i < N; ++i) cnt[i] = cnt[i / spf[i]] + (spf[i] != spf[i / spf[i]]);
}
 
// inline int cpCount(int x) {
//       int ret = 0;
//       while (x > 1) {
//             int div = spf[x];
//             while (x % div == 0) x /= div;
//             ret++;
//       }
//       return ret;
// }
 
int main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
 
      sieve();
 
      int t; cin >> t;
      while (t--) {
            int c, d, x; cin >> c >> d >> x;
            vector <int> facs;
            for (int i = 1; i * i <= x; ++i) {
                  if (x % i == 0) {
                        facs.push_back(i);
                        if (i != x / i) facs.push_back(x / i);
                  }
            }
            ll ans = 0;
            for (int g : facs) {
                  // a * b = prod st gcd(a, b) = g
                  // a / g * b / g = prod / (g * g) st gcd(a / g, b / g) = 1
                  int prod = x / g + d;
                  if (prod % c) continue;
                  prod /= c;
                  assert(prod < (int) 2e7 + 10);
                  ans += 1ll << cnt[prod];
            }
            cout << ans << '\n';
      }
}