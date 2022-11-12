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
            auto begin = chrono :: high_resolution_clock :: now();
      #endif
      ios_base :: sync_with_stdio(0);
      cin.tie(0);
 
      sieve();
 
      int t; cin >> t;
      while (t--) {
            int64_t a, b, k; cin >> a >> b >> k;
 
            // if (k > 64) {
            //       cout << "NO\n";
            //       continue;
            // }
 
            if (k == 1) {
                  if (a == b) {
                        cout << "NO\n";
                        continue;
                  }
                  if (a < b) swap(a, b);
                  cout << (a % b == 0 ? "YES\n" : "NO\n");
                  continue;
            }
 
            int total = 0;
            for (int i = 0; primes[i] * primes[i] <= a; ++i) {
                  int ct = 0;
                  while (a % primes[i] == 0) a /= primes[i], ct++;
                  total += ct;
            }
            if (a != 1) total++;
            for (int i = 0; primes[i] * primes[i] <= b; ++i) {
                  int ct = 0;
                  while (b % primes[i] == 0) b /= primes[i], ct++;
                  total += ct;
            }
            if (b != 1) total++;
 
            debug(total, k);
            cout << (total < k ? "NO\n" : "YES\n");
      }
 
      #ifdef Icry
            auto end = chrono :: high_resolution_clock :: now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << chrono :: duration_cast <chrono :: duration <double>> (end - begin).count() << " seconds]\n";  
      #endif
}