#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
using namespace std;
 
const int N = 1e6 + 100;
const int mod = 1e9 + 7;
vector <int> primes;
bitset <N> prim;
multiset <int> mp[N];
map <int, int> cnt[N];
 
void sieve() {      
      prim[1] = 1;
      for (int i = 2; i * i < N; ++i) {
            if (!prim[i]) {
                  for (int j = i * i; j < N; j += i) {
                        prim[j] = 1;
                  }
            }
      }
 
      for (int i = 2; i < N; ++i) {
            if (!prim[i]) primes.push_back(i);
      }
}
 
int64_t binpow(int64_t a, int64_t n, int64_t m) {
      if (n == 0) return 1LL;
      int64_t res = binpow(a, n >> 1LL, m) % m;
      return (((res * res) % m) * (n & 1 ? a : 1LL)) % m;
}
 
int main() {
      #ifdef Icry
            auto begin = std::chrono::high_resolution_clock::now();
      #endif
      ios_base :: sync_with_stdio(0);
      cin.tie(0);
 
      sieve();
      int n, q; cin >> n >> q;
      // map <int, multiset <int>> mp;
      // map <int, map <int, int>> cnt;
      
      auto factorize = [&](int x) {
            map <int, int> facs;
            for (int i = 0; primes[i] * primes[i] <= x; ++i) {
                  if (x % primes[i] == 0) {
                        int ct = 0;
                        while (x % primes[i] == 0) x /= primes[i], ++ct;
                        facs[primes[i]] = ct; 
                  }
            }
            if (x != 1) facs[x]++;
            return facs;
      };
 
      auto val = [&](int x) {
            if (x == 1 || (int) mp[x].size() != n) return 0;
            return *mp[x].begin();
      };
 
      for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            cnt[i] = factorize(x);
            for (auto [p, a] : cnt[i]) mp[p].insert(a);
      }
 
      int res = 1;
      for (int i = 1; i < N; ++i) res = (res * binpow(i, val(i), mod)) % mod;
 
      while (q--) {
            int id, x; cin >> id >> x; --id;
            auto dd = factorize(x);
            debug(dd);
            for (auto &[p, a] : dd) {
                  int prev = cnt[id][p];
                  cnt[id][p] += a;
                  res = (res * binpow(binpow(p, mod - 2, mod), val(p), mod)) % mod; // (1 / p) ^ min(a1, a2, a3, ...)
                  debug(prev);
                  // assert(mp[p].find(prev) != mp[p].end());
                  auto it = mp[p].lower_bound(prev);
                  if (prev != 0) mp[p].erase(it);
                  mp[p].insert(cnt[id][p]);
                  res = (res * binpow(p, val(p), mod)) % mod;
            }
            cout << res << '\n';
      }
 
      #ifdef Icry
            auto end = std::chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << std::chrono::duration_cast <std::chrono::duration <double>>(end - begin).count() << " seconds]\n";  
      #endif
}