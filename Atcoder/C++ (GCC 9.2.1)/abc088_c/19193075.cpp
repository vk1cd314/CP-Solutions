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

      vector <vector <int>> cccc(3, vector <int>(3, 0));
      for (int i = 0; i < 3; ++i) for (int j = 0; j < 3; ++j) cin >> cccc[i][j];

      int a[3], b[3];

      for (int i = 0; i <= 100; ++i) {
            memset(a, 0, sizeof a);
            memset(b, 0, sizeof b);
            bool ok = true;

            a[0] = i;
            if (a[0] > min({cccc[0][0], cccc[0][1], cccc[0][2]})) break;
            debug(3);
            for (int j = 0; j < 3; ++j) b[j] = cccc[0][j] - a[0];
            for (int j = 0; j < 3; ++j) a[j] = cccc[j][0] - b[0];

            // cerr << a[0] << ' ' << a[1] << ' ' << a[2];
            // cerr << '\n' << b[0] << ' ' << b[1] << ' ' << b[2] << '\n'; 
            for (int j = 0; j < 3; ++j) {
                  for (int k = 0; k < 3; ++k) {
                        ok &= (a[j] + b[k] == cccc[j][k]);
                  }
            }

            if (ok) {
                  cout << "Yes\n";
                  return 0;
            }
      }      

      cout << "No\n";

}
