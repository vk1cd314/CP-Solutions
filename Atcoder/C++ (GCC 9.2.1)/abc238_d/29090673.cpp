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

      // s = xor + 2 * a
      // s - 2 * a = xor
      int t; cin >> t;
      while (t--) {
            int64_t a, s; cin >> a >> s;
            auto poss = [&](int64_t s, int64_t a) {
                  if (s - 2LL * a < 0) return false;
                  int64_t x = s - 2LL * a;
                  for (int64_t i = 0; i < 61; ++i) {
                        if ((x & 1LL << i) && (a & 1LL << i)) return false;
                  }
                  return true;
            };
            cout << (poss(s, a) ? "Yes\n" : "No\n");
      }
}