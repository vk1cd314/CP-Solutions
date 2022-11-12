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
      vector <int> p(n); for (int &x : p) cin >> x;
      vector <int> q(n);
      for (int i = 0; i < n; ++i) {
            q[p[i] - 1] = i + 1;
      }
      debug(q);
      for (int x : q) cout << x << ' ';
}