#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
using namespace std;
 
const int N = 2e5 + 20;
int T[N], n;
 
void update(int id, int val) {
      for (;id <= n + 10; id += (id & -id)) T[id] += val;
}
 
int sum(int  id) {
      int sm = 0;
      for (;id > 0; id -= (id & -id)) sm += T[id];
      return sm;
}
 
int main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
 
      int t; cin >> t;
      while (t--) {
            cin >> n;
            memset(T, 0, sizeof(T[0]) * (n + 10));
            vector <pair <long long, int>> pp;
            for (int i = 1; i <= n; ++i) {
                  long long x; cin >> x;
                  if (x < i) {
                        pp.push_back({x + 1, i + 1});
                        debug(x, i);
                  }
            } 
            int sz = pp.size();
            long long ans = 0;
            debug(pp);
            for (int i = sz - 1; i >= 0; --i) {
                  ans += 1ll * sum(n + 3) - 1ll * sum(pp[i].second);
                  debug(pp[i].second - 1, sum(n + 3) - sum(pp[i].second));
                  debug(sum(n + 3));
                  update(pp[i].first, 1);
            }
            cout << ans << '\n';
            
      }
}