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

      int n, q; cin >> n >> q;
      vector <long long> a(n), p(n);
      for (auto &x : a) cin >> x;
      sort(a.begin(), a.end());
      p[0] = a[0];
      for (int i = 1; i < n; ++i) p[i] = p[i - 1] + a[i];
      debug(a, p);
      while (q--) {
            long long x; cin >> x;
            auto it = lower_bound(a.begin(), a.end(), x);
            long long id = it - a.begin();
            long long lft = 0;
            if (id > 0) lft = x * id - p[id - 1];
            long long rgt = 0;
            if (id < n) rgt = p[n - 1] - (id ? p[id - 1] : 0) - x * (n - id);
            cout << lft + rgt << '\n'; 
      }
}