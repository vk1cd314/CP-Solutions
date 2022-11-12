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
            vector <int> a(n); for (int &x : a) cin >> x;
            int x = a.back();
            int k = 0;
            for (int i = n - 2; i >= 0; --i) {
                  if (a[i] > x) x = a[i], ++k;
            }
            cout << k << '\n';
      }
}