#include <bits/stdc++.h>

using namespace std;

#ifdef BOI
#include "debug.h"
#else
#define debug(args...)
#endif

long long binpow(long long a, long long n, long long m) {
      if (n == 0) return 1LL;
      long long res = binpow(a, n >> 1LL, m) % m;
      return (((res * res) % m) * (n & 1 ? a : 1LL)) % m;
}

int main() {
      ios_base :: sync_with_stdio(0);
      cin.tie(0);

      long long n, m; cin >> n >> m;
      cout << (binpow(10LL, n, m * m) / m);
}
