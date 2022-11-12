#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif

using namespace std;

const int N = 1e6 + 10;
int T[N], n;

void update(int id, int val) {
      for (;id <= n; id += (id & -id)) T[id] += val;
}

int sum(int id) {
      int sm = 0;
      for (;id > 0; id -= (id & -id)) sm += T[id];
      return sm;
}

void range_up(int l, int r, int val) {
    update(l, val);
    update(r + 1, -val);
}

int main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);

      int t; cin >> t;
      while (t--) {
            cin >> n;
            memset(T, 0, sizeof(T[0]) * (n + n));
            vector <pair <int, int>> a;
            for (int i = 0; i < n; ++i) {
                  int l, r; cin >> l >> r;
                  // if (l <= i + 1 && i + 1 <= r) continue;
                  range_up(l, r, 1);
                  a.push_back({l, r});
            }
            vector <int> lo;  
            for (int i = 1; i <= n; ++i) {
                  if (sum(i) == n - 1 && !(a[i - 1].first <= i && i <= a[i - 1].second)) {
                        lo.push_back(i);
                  }
            }
            cout << lo.size() << '\n';
            for (int x : lo) cout << x << '\n';
      }
}