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
            for (int i = 0; i < n; ++i) {
                  int bi; cin >> bi;
                  string s; cin >> s;
                  for (char c : s) {
                        if (c == 'U') a[i] = (a[i] - 1 + 10) % 10;
                        else a[i] = (a[i] + 1) % 10; 
                  }
            } 
            for (int x : a) cout << x << ' ';
            cout << '\n';
      }
}