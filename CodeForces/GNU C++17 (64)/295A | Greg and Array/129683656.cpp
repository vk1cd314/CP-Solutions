#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
using namespace std;
 
// const int N = 1e5 + 10;
struct fenwick_tree {
      vector <long long> T;
      int n;
      
      fenwick_tree(int _n): n(_n), T(_n + 2) {}
 
      void update(int id, long long val) {
            for (; id <= n; id += (id & -id)) T[id] += val;
      }
 
      long long point_query(int idx) {
            long long ret = 0;
            for (; idx > 0; idx -= idx & -idx) ret += T[idx];
            return ret;
      }
 
      void range_add(int l, int r, long long val) {
            update(l, val);
            update(r + 1, -val);
      }
};
 
int main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
 
      int n, m, k; cin >> n >> m >> k;
      fenwick_tree fek(m + 2), fek1(n + 2);
      vector <long long> a(n + 1), d(m + 1);
      vector <int> l(m + 1), r(m + 1), x(k + 1), y(k + 1);
      for (int i = 1; i <= n; ++i) cin >> a[i];
      for (int i = 1; i <= m; ++i) cin >> l[i] >> r[i] >> d[i];
      for (int i = 1; i <= k; ++i) cin >> x[i] >> y[i];
 
      for (int i = 1; i <= k; ++i) fek.range_add(x[i], y[i], 1);
      for (int i = 1; i <= m; ++i) fek1.range_add(l[i], r[i], fek.point_query(i) * d[i]);
 
      for (int i = 1; i <= n; ++i) {
            cout << a[i] + fek1.point_query(i) << ' ';
      }
      cout << '\n';
}