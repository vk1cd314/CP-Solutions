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

      int cnt = 0;
      for (int i = 1; i <= n; ++i) {
            vector <int> dig;
            int tmp = i;
            while (tmp) {
                  dig.push_back(tmp % 8);
                  tmp /= 8;
            }
            
            bool ok1 = true, ok2 = true; 
            for (int x : dig) if (x == 7) ok1 = false;

            tmp = i;
            dig.clear();
            while (tmp) {
                  dig.push_back(tmp % 10);
                  tmp /= 10;
            }

            // debug(i, dig);
            for (int x : dig) if (x == 7) ok2 = false;

            if (ok1 && ok2) ++cnt;
      }   

      cout << cnt << endl;
}
