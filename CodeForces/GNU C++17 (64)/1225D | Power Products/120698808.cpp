#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
using namespace std;
 
const int N = 1e6;
vector <int> primes;
bitset <N> prim;
 
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
 
int main() {
      #ifdef Icry
            auto begin = chrono::high_resolution_clock::now();
      #endif
      ios_base::sync_with_stdio(0);
      cin.tie(0);
 
      sieve();
      int n, k; cin >> n >> k;
      auto decomp = [&](int x) {
            vector <pair <int, int>> ret;
            for (int i = 0; primes[i] * primes[i] <= x; ++i) {
                  int ct = 0;
                  while (x % primes[i] == 0) x /= primes[i], ct++;
                  if (ct % k) ret.push_back({primes[i], ct % k});
            }
            if (x > 1) ret.push_back({x, 1});
            return ret;
      };
 
      int64_t ans = 0;
      map <vector <pair <int, int>>, int64_t> cnt;
      vector <pair <int, int>> v, vv;
      for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            v = decomp(x);
            vv = v;
            for (auto &[p, ct] : v) ct = k - ct;
            ans += cnt[v];
            cnt[vv]++;
      }
 
      cout << ans << '\n';
 
      #ifdef Icry
            auto end = chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << chrono::duration_cast <chrono :: duration <double>> (end - begin).count() << " seconds]\n";  
      #endif
}