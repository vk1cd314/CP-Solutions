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
            int64_t n, k; cin >> n >> k;
            string s = to_string(n);
            set <char> ss;
            int mask = 0;
            int64_t ans = LLONG_MAX;
            string aa, curr;
            char mn = '9';
            for (char c : s) {
                  for (char d = c + 1; d <= '9'; ++d) {
                        if (__builtin_popcount(mask | 1 << d - '0') > k) continue;
                        bool kek = __builtin_popcount(mask | 1 << d - '0') != k;
 
                        char nwmn = min(mn, kek ? '0' : d);
 
                        string cc = curr; cc += d;
                        while (stoll(cc) < n) cc += nwmn;
 
                        ans = min(ans, (int64_t) stoll(cc));
                  }
                  ss.insert(c);
                  curr += c;
                  mask |= (1 << c - '0');
                  mn = min(mn, c);
            }
            if ((int) ss.size() <= k) cout << s << '\n';
            else cout << ans << '\n';
      }
}