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
            int64_t curr = 0, prev = 0, ext = 0;
            for (int i = 0; i < n; ++i) {
                  if (a[i] <= i + 1 + curr) {
                        prev = a[i];
                        continue;
                  }
                  else {
                        debug(a[i], i + 1);
                        int64_t diff = a[i] - (i + 1 + curr);
                        curr += max(int64_t(0), diff);
                  }
            }
            cout << curr << '\n';
      }
}