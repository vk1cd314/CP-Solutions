#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
using namespace std;
 
const int N = 2e5 + 10;
int dp[N];
vector <int> pos[30];
string s;
 
int rec(int i) {
      if (i == (int) s.size()) return 0;
      int &ret = dp[i];
      if (~ret) return ret;
      ret = 1e9;
      ret = min(ret, 1 + rec(i + 1));
      auto it = upper_bound(pos[s[i] - 'a'].begin(), pos[s[i] - 'a'].end(), i);
      if (it != pos[s[i] - 'a'].end()) ret = min(ret, *it - i - 1 + rec(*it + 1));
      return ret;
}
 
int main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
 
      int t; cin >> t;
      while (t--) {
            memset(dp, -1, sizeof dp);
            for (int i = 0; i < 30; ++i) pos[i].clear();
            cin >> s;
            for (int i = 0; i < (int) s.size(); ++i) pos[s[i] - 'a'].push_back(i);
            cout << rec(0) << '\n';
      }
}