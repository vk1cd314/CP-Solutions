#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
using namespace std;
 
const int MOD = 1e9 + 7;
 
struct modint {
      int x; explicit operator int() const { return x; }
      modint() { x = 0; }
      modint (int64_t x) : x(x % MOD) { if (x < 0) x += MOD; }
      friend bool operator == (const modint& a, const modint& b) { return a.x == b.x; }
      friend bool operator != (const modint& a, const modint& b) { return !(a == b); }
      friend bool operator < (const modint& a, const modint& b) { return a.x < b.x; }
      modint& operator += (const modint& y) { if ((x += y.x) >= MOD) x -= MOD; return *this; }
      modint& operator -= (const modint& y) { if ((x -= y.x) < 0) x += MOD; return *this; }
      modint& operator *= (const modint& y) { x = int((int64_t) x * y.x % MOD); return *this; }
      modint& operator /= (const modint& m) { return (*this) *= inv(m); }
      friend modint pow(modint a, int64_t p) { modint ans(1); for (; p; p >>= 1, a *= a) if (p & 1) ans *= a; return ans; }
      friend modint inv(const modint& a) { return pow(a, MOD - 2); }
      modint operator - () const { return modint(-x); }
      modint& operator ++ () { return *this += 1; }
      modint& operator -- () { return *this -= 1; }
      friend modint operator + (modint a, const modint& b) { return a += b; }
      friend modint operator - (modint a, const modint& b) { return a -= b; }
      friend modint operator * (modint a, const modint& b) { return a *= b; }
      friend modint operator / (modint a, const modint& b) { return a /= b; }
      friend ostream& operator << (ostream& os, const modint& a) { os << a.x; return os; }
};
 
using mint = modint;
const int N = 3e6 + 10;
const mint inv3 = inv(mint(3));
 
mint fac[N], invfac[N], f[N];
 
mint C(int n, int k) {
      if (k > n) return 0;
      if (k == 0) return 1;
      return fac[n] * invfac[n - k] * invfac[k];
}
 
int main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
 
      fac[0] = 1;
      for (int i = 1; i < N; ++i) fac[i] = fac[i - 1] * mint(i);
 
      invfac[N - 1] = inv(fac[N - 1]);
      for (int i = N - 2; i >= 0; --i) invfac[i] = invfac[i + 1] * mint(i + 1);
 
      int n, q; cin >> n >> q;
 
      f[1] = f[2] = 0;
      for (int i = 1; i <= n; ++i) f[1] += C(3 * i, 1), f[2] += C(3 * i, 2);
 
      for (int x = 4; x <= 3 * n + 1; ++x) {
            f[x - 1] = (C(3 * n + 3, x) - 3 * f[x - 2] - f[x - 3]) * inv3;
      }
 
      while (q--) {
            int x; cin >> x;
            cout << f[x] << '\n';
      }
}