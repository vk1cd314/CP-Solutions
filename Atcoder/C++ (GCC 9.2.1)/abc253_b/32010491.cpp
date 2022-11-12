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

      int h, w; cin >> h >> w;
      vector <string> a(h);
      for (auto &x : a) cin >> x;
      // for (auto x : a) cout << x << '\n';
      pair <int, int> st = {-1, -1};
      pair <int, int> ed = {-1, -1};
      for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                  if (st == make_pair(-1, -1) && a[i][j] == 'o') st = {i, j};
                  else if (ed == make_pair(-1, -1) && a[i][j] == 'o') ed = {i, j}; 
            }
      }
      debug(st, ed);
      cout << abs(st.first - ed.first) + abs(ed.second - st.second) << '\n';
}