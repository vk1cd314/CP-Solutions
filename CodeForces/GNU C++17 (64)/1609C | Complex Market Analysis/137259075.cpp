#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
using namespace std;
 
const int N = 1e6 + 1;
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
      ios_base::sync_with_stdio(0);
      cin.tie(0);
 
      sieve();
 
      int t; cin >> t;
      while (t--) {
            int n, e; cin >> n >> e;
            vector <int> a(n); for (int &x : a) cin >> x;
            int64_t ans = 0;
            for (int i = 0; i < n; ++i) {
                  if (!prim[a[i]]) {
                        int64_t l = 1, r = 1;
                        int k = 1;
                        while (i + e * k < n && a[i + e * k] == 1) ++l, ++k;
                        k = 1;
                        while (i - e * k >= 0 && a[i - e * k] == 1) ++r, ++k;
                        ans += l * r - 1;
                  }
            }
            cout << ans << '\n';
      }
}