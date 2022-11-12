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

      map <int, int> fr;
      for (int x : a) {
            fr[x - 1]++;
            fr[x]++;
            fr[x + 1]++; 
      }
      
      int mx = -1;
      for (auto [x, y] : fr) mx = max(mx, y);
      
      cout << mx << endl;
}
