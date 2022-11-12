#include <bits/stdc++.h>

using namespace std;

#ifdef BOI
#include "debug.h"
#else
#define debug(args...)
#endif

int main() {
      ios_base :: sync_with_stdio(0);
      cin.tie(0);

      int n; cin >> n;
      vector <int> a(n); for (int& x : a) cin >> x;
      int mx = *max_element(a.begin(), a.end());
      int ans, cnt = -1;
      for (int i = 2; i <= mx; ++i) {
            int f = 0;
            for (int j = 0; j < n; j++) {
                  f += (a[j] % i == 0);
            }
            if (f > cnt) {
                  ans = i;
                  cnt = f;
            }
      }      

      cout << ans << endl;
}
