#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
using namespace std;
 
const int MOD = 998244353;
 
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
 
const int N = 1e5 + 2;
using mint = modint;
 
mint fac[N], invfac[N];
 
mint C(int n, int k) {
      if (k > n) return 1LL;
      if (k == 0) return 1LL;
      return fac[n] * invfac[n - k] * invfac[k];
}
 
int main() {
      #ifdef Icry
            auto begin = chrono::high_resolution_clock::now();
      #endif
      ios_base::sync_with_stdio(0);
      cin.tie(0);
 
      fac[0] = 1;
      for (int i = 1; i < N; ++i) fac[i] = fac[i - 1] * mint(i);
 
      invfac[N - 1] = inv(fac[N - 1]);
      for (int i = N - 2; i >= 0; --i) invfac[i] = invfac[i + 1] * mint(i + 1);
 
      int t; cin >> t;
      while (t--) {
            int n; cin >> n;
            string s; cin >> s;
            int zero = count(s.begin(), s.end(), '0');
            int pone = 0;
            for (int i = 0; i < n; ++i) {
                  int j = i;
                  while (j < n && s[j] == '1') j++;
                  pone += j - i >> 1;
                  i = j;
            }
            debug(zero, pone);
            cout << C(zero + pone, pone) << '\n';
      }
 
      #ifdef Icry
            auto end = chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << chrono::duration_cast <chrono :: duration <double>> (end - begin).count() << " seconds]\n";  
      #endif
}