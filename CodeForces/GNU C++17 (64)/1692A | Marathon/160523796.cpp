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
            vector <int> a(4);
            for (int &x : a) cin >> x;
            int x = a[0];
            int ct = 0;
            for (int xx : a) ct += xx > x;
            cout << ct << '\n';
      }
}