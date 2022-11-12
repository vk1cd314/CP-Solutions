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
            char c; cin >> c;
            string s; cin >> s;
            map <char, vector <int>> mp;
            s += s;
            n += n;
            for (int i = 0; i < n; ++i) {
                  mp[s[i]].push_back(i);
            }
            int ans = INT_MIN;
            for (auto x : mp[c]) {
                  auto it = lower_bound(mp['g'].begin(), mp['g'].end(), x);
                  if (it == mp['g'].end()) continue;
                  int id = *it - x;
                  ans = max(ans, id);
            }
            cout << ans << '\n';
      }
}