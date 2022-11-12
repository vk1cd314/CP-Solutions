#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
using namespace std;
 
const int N = 1e4;
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
 
      int n; cin >> n;
      vector <int> d1(n, -1), d2(n, -1);
 
      auto getfacs = [&](int n) {
            vector <int> ret;
            for (int i = 0; primes[i] * primes[i] <= n; ++i) {
                  int ct = 0;
                  while (n % primes[i] == 0) n /= primes[i], ct++;
                  if (ct) ret.push_back(primes[i]);
            }
            if (n > 1) ret.push_back(n);
            return ret;
      };
 
      for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            auto facs = getfacs(x);
            if (facs.size() < 2) continue;
            d1[i] = facs[0], d2[i] = 1;
            for (int j = 1; j < (int) facs.size(); ++j) d2[i] *= facs[j];
      }
 
      for (int x : d1) cout << x << ' ';
      cout << '\n';
      for (int x : d2) cout << x << ' ';
 
 
      #ifdef Icry
            auto end = chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << chrono::duration_cast <chrono :: duration <double>> (end - begin).count() << " seconds]\n";  
      #endif
}