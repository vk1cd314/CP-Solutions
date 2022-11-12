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

      int t; cin >> t;
      while (t--) {
            int n; cin >> n;
            map <int, int> m1, m2;
            int mx = -1;
            for (int i = 0; i < n; ++i) {
                  int x; cin >> x;
                  m1[x]++;
            }
            for (auto [x, y] : m1) {
                  m2[y]++;
                  if (y > mx) {
                        mx = y;
                  }
            }
            cout << (m2[mx] == 1 ? "YES\n" : "NO\n");

      }
}