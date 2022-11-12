#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
using namespace std;
 
int main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
 
      int t; cin >> t;
      while (t--) {
            int n; cin >> n;
            if (n == 3) {
                  cout << "-1\n";
                  continue;
            }
            if (n == 5) {
                  cout << "5 4 1 2 3\n";
                  continue;
            }
            if (n % 2 == 0) {
                  vector <int> a(n);
                  iota(a.begin(), a.end(), 1);
                  reverse(a.begin(), a.end());
                  for (int x : a) cout << x << ' ';
                  cout << '\n';
            } else {
                  vector <int> a(n - 1);
                  int gp = (n - 1) / 2;
                  iota(a.begin(), a.end(), 1);
                  for (int i = 0; i < n - 1; i += 2) {
                        swap(a[i], a[i + 1]);
                  }
                  cout << n << ' ';
                  for (int i = 2 * gp - 2; i < n - 1; ++i) {
                        cout << a[i] << ' ';
                  }
                  for (int i = 0; i < 2 * (gp - 1); ++i) {
                        cout << a[i] << ' ';
                  }
                  cout << '\n';
            }
 
      }
}
// 5 3 4 2 1
// 2 1 4 3 5