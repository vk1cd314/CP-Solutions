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
      vector <int> a(n); for (int &x : a) cin >> x;
      vector <int> cuts;
      int ang = 0;
      cuts.push_back(0);
      for (int i = 0; i < n; ++i) {
            ang += a[i];
            ang %= 360;
            cuts.push_back(ang);
      }
      sort(cuts.begin(), cuts.end());
      int ans = 0;
      for (int i = 0; i + 1 < (int) cuts.size(); ++i) {
            ans = max(ans, cuts[i + 1] - cuts[i]);
      }
      ans = max(ans, 360 - cuts.back());
      cout << ans << '\n';
}