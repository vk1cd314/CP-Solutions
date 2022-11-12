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
      vector <int> a(n); for (int& x : a) cin >> x, --x;

      int curr = 0, cnt = 0;
      bool ok = true;
      while (3) {
            if (curr == 1) {
                  break;
            }
            if (cnt == n) {
                  ok = false;
                  break;
            }
            cnt++;
            curr = a[curr];
      }    

      if (!ok) cout << "-1\n";
      else cout << cnt << endl;
}
