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
            map <int, int> ct;
            set <int> have;
            for (int i = 0; i < n; ++i) {
                  int x; cin >> x;
                  have.insert(x);
                  ct[x]++;
            }
            for (auto [x, y] : ct) {
                  if (y > 1) have.insert(-x);
            }
            cout << have.size() << '\n';
      }
}