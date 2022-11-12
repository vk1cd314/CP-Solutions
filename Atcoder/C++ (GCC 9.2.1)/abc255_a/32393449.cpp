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

      int r, c; cin >> r >> c;
      int a[2][2];
      for (int i = 0; i < 2; ++i) for (int j = 0; j < 2; ++j) cin >> a[i][j];
      cout << a[r - 1][c - 1];
}