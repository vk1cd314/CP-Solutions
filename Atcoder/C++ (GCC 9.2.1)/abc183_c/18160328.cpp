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
      ll k; cin >> k;
      vector <vector <ll>> a(n, vector <ll>(n));
      for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                  cin >> a[i][j];
            }
      }      

      vector <int> aa(n);
      iota(aa.begin(), aa.end(), 0);
      int cnt = 0;
      do {
            ll sum = 0;
            for (int i = 1; i < n; ++i) {
                  sum += a[aa[i]][aa[i - 1]];
            }
            sum += a[aa[n - 1]][0];
            if (sum == k) ++cnt;
            debug(aa, sum);
      } while (next_permutation(aa.begin() + 1, aa.end()));

      cout << cnt;
}     
