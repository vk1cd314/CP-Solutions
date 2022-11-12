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

      int n; cin >> n;
      map <int, set <pair <int, int>>> mp;
      for (int i = 0; i < n; ++i) {
            int mi; cin >> mi;
            for (int j = 0; j < mi; ++j) {
                  int p, e; cin >> p >> e;
                  mp[p].insert({e, i});
            }
      }
      debug(mp);
      set <int> diff;
      diff.insert(n);
      for (auto &[val, ss] : mp) {
            if ((int)ss.size() == 1) {
                  diff.insert((*ss.begin()).second);
            } else {
                  auto it = *ss.rbegin(); ss.erase(--ss.end());
                  if ((*ss.rbegin()).first != it.first) diff.insert(it.second);
            }
      }
      int ans = min((int) diff.size(), n);
      cout << ans << '\n';
}