#include <bits/stdc++.h>

using namespace std;

#ifdef BOI
#include "debug.h"
#else
#define debug(args...)
#endif

struct segtree {
      int size;
      vector <int64_t> tree;
      int NEUTRAL = INT_MAX;

      void init(int n) {
            size = 1LL;
            while (size < n) size <<= 1;
            tree.assign(size << 1, 0);
      }

      void build(vector <int64_t>& a, int x, int lx, int rx) {
            if (rx - lx == 1) {
                  if (lx < (int) a.size()) tree[x] = a[lx];
                  return;
            }
            int mid = lx + (rx - lx) / 2;
            build(a, (x << 1) + 1, lx, mid);
            build(a, (x << 1) + 2, mid, rx);
            tree[x] = min(tree[(x << 1) + 1], tree[(x + 1) << 1]);
      }

      void build(vector <int64_t>& a) {
            build(a, 0, 0, size);
      }

      int64_t query(int l, int r, int x, int lx, int rx) {
            if (lx >= r || l >= rx) return NEUTRAL;
            if (l <= lx && rx <= r) return tree[x];
            int mid = lx + (rx - lx) / 2;
            int64_t m1 = query(l, r, (x << 1) + 1, lx, mid);
            int64_t m2 = query(l, r, (x + 1) << 1, mid, rx);
            return min(m1, m2);
      }

      int64_t query(int l, int r) {
            assert(l <= r);
            return query(l, r, 0, 0, size);
      }
};

int main() {
      ios_base :: sync_with_stdio(0);
      cin.tie(0);

      int n; cin >> n;
      vector <int64_t> a(n); for (auto& x : a) cin >> x;

      // segtree st;
      // st.init(n);
      // st.build(a);

      int64_t ans = 0;
      debug(a);
      for (int i = 0; i < n; ++i) {
            int64_t ff = a[i];
            for (int j = i; j < n; ++j) {
                  ff = min(ff, a[j]);
                  debug(i, j, ff);
                  ans = max((long long) ans, 1LL * (j - i + 1) * ff);
            }
      }

      cout << ans << '\n';
}
