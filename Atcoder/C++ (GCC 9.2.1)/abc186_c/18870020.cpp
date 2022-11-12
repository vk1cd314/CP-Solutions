#include <bits/stdc++.h>

using namespace std;

#ifdef BOI
#include "debug.h"
#else
#define debug(args...)
#endif

typedef long long ll;

int main() {
      ios_base :: sync_with_stdio(0);
      cin.tie(0);

      int n; cin >> n;
      vector <ll> a(n); for (ll& x : a) cin >> x;
      sort(a.begin(), a.end());

      ll sum = 0;
      for (int i = n - 1; i >= 0; --i) {
            sum += 1LL * i * a[i] - (n - i - 1) * 1LL * a[i];
      }

      cout << sum << endl;
}
