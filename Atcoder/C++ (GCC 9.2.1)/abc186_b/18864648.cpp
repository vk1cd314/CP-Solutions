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

      vector <vector <int>> a(h, vector <int> (w));

      int sum = 0, mn = INT_MAX;
      for (auto& x : a) for (int& y : x) {
            cin >> y;
            sum += y;
            mn = min(mn, y);
      }

      cout << sum - h * w * mn << endl;
     
}
