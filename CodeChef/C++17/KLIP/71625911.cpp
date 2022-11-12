#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...)
#endif

using namespace std;

const int N = 1e5 + 10;

struct BIT {
      long long M[N], A[N];
      BIT() {
            memset(M, 0, sizeof M);
            memset(A, 0, sizeof A);
      }
      void update(int i, long long mul, long long add) {
            while (i < N) {
                  M[i] += mul;
                  A[i] += add;
                  i |= (i + 1);
            }
      }
      void upd(int l, int r, long long x) {
            update(l, x, -x * (l - 1));
            update(r, -x, x * r);
      }
      long long query(int i) {
            long long mul = 0, add = 0;
            int st = i;
            while (i >= 0) {
                  mul += M[i];
                  add += A[i];
                  i = (i & (i + 1)) - 1;
            }
            return (mul * st + add);
      }
      long long query(int l, int r) {
            return query(r) - query(l - 1);
      }
} bt;

int main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);

      int t;
      cin >> t;
      while (t--) {
            int n, k;
            cin >> n >> k;
            memset(bt.M, 0, sizeof(bt.M[0]) * (n + 10));
            memset(bt.A, 0, sizeof(bt.A[0]) * (n + 10));
            string s;
            cin >> s;
            int have = n - k + 1;
            debug(have);
            for (int i = 0; i + k <= n; ++i) {
                  // [i, i + k - 1]
                  int cc = s[i] - '0' + bt.query(i, i);
                  if ((cc & 1) && have > 0) {
                        debug(i);
                        have--;
                        bt.upd(i, i + k - 1, 1);
                  }
            }
            for (int i = 0; i < n; ++i) {
                  int cc = s[i] - '0' + bt.query(i, i);
                  s[i] = (cc & 1 ? '1' : '0');
            }
            cout << s << '\n';

      }
}