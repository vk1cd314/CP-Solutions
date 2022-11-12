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
            string s; cin >> s;
            string s1, s2;
            s1 += s[0], s2 += s[0];
            for (int i = 1; i < n; ++i) {
                  if (s[i] < s[i - 1]) s1 += s[i];
                  else break;
            }
            for (int i = 1; i < n; ++i) {
                  if (s[i] <= s[i - 1]) s2 += s[i];
                  else break;
            }
            string t1 = s1, t2 = s2;
            reverse(t1.begin(), t1.end());
            reverse(t2.begin(), t2.end());
            s1 += t1, s2 += t2;
            cout << min(s1, s2) << '\n';
      }
}