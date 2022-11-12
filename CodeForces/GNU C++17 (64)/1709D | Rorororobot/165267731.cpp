#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
using namespace std;
 
struct item {
      int mx;
};
 
struct segtree {
      vector<item> seg;
      int sz = 1;
      item NEUTRAL = {-1};
      item single(int a) {
            return {a};
      }
      item merge(item a, item b) {
            return {max(a.mx, b.mx)};
      }
      void init(int n) {
            while (sz < n) sz *= 2;
            seg.resize(2 * sz);
      }
      void build(vector<int> &a, int x, int lx, int rx) {
            if (rx - lx == 1) {
                  if (lx < (int)a.size()) seg[x] = single(a[lx]);
                  return;
            }
            int mx = (lx + rx) / 2;
            build(a, 2 * x + 1, lx, mx);
            build(a, 2 * x + 2, mx, rx);
            seg[x] = merge(seg[2 * x + 1], seg[2 * x + 2]);
      }
      void build(vector<int> &a) {
            build(a, 0, 0, sz);
      }
      item calc(int x, int lx, int rx, int i, int j) {
            if (lx >= j || rx <= i) return NEUTRAL;
            if (lx >= i && rx <= j) return seg[x];
            int mx = (lx + rx) / 2;
            item i1 = calc(2 * x + 1, lx, mx, i, j);
            item i2 = calc(2 * x + 2, mx, rx, i, j);
            return merge(i1, i2);
      }
      item calc(int i, int j) {
            return calc(0, 0, sz, i, j);
      }
      void set(int i, int v, int x, int lx, int rx) {
            if (rx - lx == 1) {
                  seg[x] = single(v);
                  return;
            }
            int mx = (lx + rx) / 2;
            if (i < mx)
                  set(i, v, 2 * x + 1, lx, mx);
            else
                  set(i, v, 2 * x + 2, mx, rx);
            seg[x] = merge(seg[2 * x + 1], seg[2 * x + 2]);
      }
      void set(int i, int v) {
            set(i, v, 0, 0, sz);
      }
};
 
int main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
 
      int n, m; cin >> n >> m;
      vector <int> a(m); for (int &x : a) cin >> x;
      segtree st;
      st.init(m); st.build(a);
      int q; cin >> q;
      while (q--) {
            long long xs, ys, xf, yf, k; cin >> xs >> ys >> xf >> yf >> k;
            if (ys > yf) swap(xs, xf), swap(ys, yf);
            if (xs % k != xf % k || ys % k != yf % k) {
                  cout << "NO\n";
                  continue;
            }
            long long mx = st.calc(ys - 1, yf).mx;
            // xs + k * x < n
            // x < (n - xs) / k
            long long mxH = xs + (n - xs) / k * k;
            debug(mx, mxH);
            if (mxH > mx) cout << "YES\n";
            else cout << "NO\n";
      }
 
}