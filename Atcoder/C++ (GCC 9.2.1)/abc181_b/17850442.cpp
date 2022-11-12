#include <bits/stdc++.h>

using namespace std;

#ifdef BOI
#include "debug.h"
#else
#define debug(args...)
#endif

int main() {
      ios_base :: sync_with_stdio(0);
      cin.tie(0);

      int n; cin >> n;

      long long sum = 0;
      while (n--) {
            long long a, b; cin >> a >> b;
            sum += (b * (b + 1)) / 2;
            sum -= (a * (a - 1)) / 2;
      }      
      cout << sum;
}
