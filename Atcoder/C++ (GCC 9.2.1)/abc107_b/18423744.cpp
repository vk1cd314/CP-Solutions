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

      int h, w; cin >> h >> w;
      vector <string> gr(h);
      for (string& x : gr) cin >> x;
      vector <int> row(h, 0), col(w, 0);
      for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                  if (gr[i][j] == '.') row[i]++, col[j]++;
            }
      }      

      debug(row, col);
      for (int i = 0; i < h; ++i) {
            bool ok = false;
            for (int j = 0; j < w; ++j) {
                  if (row[i] == w || col[j] == h){
                        69;
                  }
                  else {
                        cout << gr[i][j];
                        ok = true;
                  }
            }
            if (ok) cout << endl;
      }
}
