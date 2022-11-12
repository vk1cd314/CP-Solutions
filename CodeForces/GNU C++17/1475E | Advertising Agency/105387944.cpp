#include <bits/stdc++.h>
 
using namespace std;
 
#ifdef BOI
#include "debug.h"
#else
#define debug(args...)
#endif
 
const long long mod = 1e9 + 7;
 
const int N = 1e4;
long long fac[N];
 
long long binpow(long long a, long long n, long long m = mod) {
      if (n == 0) return 1LL;
      long long res = binpow(a, n >> 1LL) % m;
      return (((res * res) % m) * (n & 1 ? a : 1LL)) % m;
}
 
long long bincoeff(long long n, long long k) {
      if (k > n) return 1LL;
      if (k == 0) return 1LL;
      long long res = (fac[n] * binpow(fac[k], mod - 2)) % mod;
      res = (res * binpow(fac[n - k], mod - 2)) % mod;
      return res;
}
 
int main() {
      ios_base :: sync_with_stdio(0);
      cin.tie(0);
 
      fac[0] = 1;
      for (int i = 1; i < N; ++i) fac[i] = (i * fac[i - 1]) % mod;
 
      int t; cin >> t;
      while (t--) {
            long long n, k; cin >> n >> k;
 
            vector <int> a(n); for (int& x : a) cin >> x;
            sort(a.rbegin(), a.rend());
 
            map <int, long long> fr;
            for (int x : a) fr[x]++;
 
            map <int, long long> ase;
            for (int i = 0; i < k; ++i) ase[a[i]]++; 
            long long ans = 1;
            ans = (ans * bincoeff(fr[a[k - 1]], ase[a[k - 1]])) % mod;
 
            cout << ans << '\n';
      }    
}