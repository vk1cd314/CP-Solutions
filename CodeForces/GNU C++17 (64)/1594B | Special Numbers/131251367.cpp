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
 
int main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
 
      int t; cin >> t;
      while (t--) {
            int64_t n, k; cin >> n >> k;
            mint pw = 1, ans = 0;
            for (int i = 0; i <= 32; ++i) {
                  if (k & 1LL << i) ans += pw;
                  pw *= n;
            }
            cout << ans << '\n';
      }
}