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
      string s; cin >> s;
      int x = 0, y = 0;
      int dx[4] = {1, 0, -1, 0};
      int dy[4] = {0, -1, 0, 1};
      int dir = 0;
      for (int i = 0; i < n; ++i) {
            if (s[i] == 'S') {
                  x += dx[dir];
                  y += dy[dir];
            } else dir = (dir + 1) % 4;
      }
      cout << x << ' ' << y << '\n';
}