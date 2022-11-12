#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif

using namespace std;

const int N = 200;
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

      int a, b, c, d; cin >> a >> b >> c >> d;
      bool takahashi = false;
      for (int i = a; i <= b; ++i) {
            bool ok = true;
            for (int j = c; j <= d; ++j) {
                  ok &= prim[i + j];
            }
            takahashi |= ok;
      }

      cout << (takahashi ? "Takahashi" : "Aoki");

}