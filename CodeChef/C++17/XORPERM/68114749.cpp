#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif

using namespace std;

int main() {
      // ios_base::sync_with_stdio(0);
      // cin.tie(0);

      int t; cin >> t;
      while (t--) {
            int n; cin >> n;
            // vector <int> a(n); iota(a.begin(), a.end(), 1);
            // do {
            //       bool ok = true;
            //       for (int i = 0; i + 2 < n; ++i) {
            //             ok &= ((a[i] ^ a[i + 1]) != a[i + 2]);
            //       }
            //       if (ok && a[1] == n && a[0] == 1) {
            //             debug(a);
            //       }
            // } while (next_permutation(a.begin(), a.end()));
            if (n == 3) cout << "-1\n";
            else {
                  cout << "1 " << n << " ";
                  for (int i = 2; i < n; ++i) cout << i << ' ';
                  cout << '\n';
            }
      }
}