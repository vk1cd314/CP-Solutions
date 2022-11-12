#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
using namespace std;
 
int main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
 
      int t; cin >> t;
      while (t--) {
            int n; cin >> n;
            int64_t sum = 0, kek = 0, rest = 0;
            vector <int64_t> a(n); for (int64_t &x : a) {
                  cin >> x, sum += x;
                  int64_t b = x;
                  while (b % 2 == 0) b /= 2, kek++;
                  rest += b;
            }
            for (int64_t x : a) {
                  int64_t c = x;
                  int64_t d = 0;
                  while (c % 2 == 0) c /= 2, d++;
                  int64_t p = x * (1LL << (kek - d));
                  sum = max(sum, p + rest - c);
            }
            cout << sum << '\n';
      }
}