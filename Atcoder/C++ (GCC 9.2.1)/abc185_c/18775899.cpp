#include <bits/stdc++.h>

using namespace std;

#ifdef BOI
#include "debug.h"
#else
#define debug(args...)
#endif

void fuck(int n, int r){
      long long p = 1, k = 1;

      if (n - r < r)
            r = n - r;

      if (r != 0) {
            while (r) {
                  p *= n;
                  k *= r;

                  long long m = __gcd(p, k);
                  p /= m;
                  k /= m;

                  n--;
                  r--;
            }
      }
      else p = 1;

      cout << p << endl;
}

int main()
{
      ios_base ::sync_with_stdio(0);
      cin.tie(0);

      long long l;
      cin >> l;
      fuck(l - 1, 11);
}
