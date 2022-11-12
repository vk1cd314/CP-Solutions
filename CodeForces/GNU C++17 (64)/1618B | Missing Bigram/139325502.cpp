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
            string s;
            vector <string> a(n - 2);
            int lst = -1;
            cin >> a[0];
            for (int i = 1; i < n - 2; ++i) {
                  cin >> a[i];
                  if (a[i][0] != a[i - 1][1]) lst = i;
            }
            if (lst == -1) {
                  s = a[0][0];
                  s += a[0];
                  for (int i = 1; i < n - 2; ++i) s += a[i][1];
            } else {
                  s = a[0];
                  for (int i = 1; i < lst; ++i) s += a[i][1];
                  s += a[lst][0];
                  for (int i = lst; i < n - 2; ++i) s += a[i][1];
            }
            
            cout << s << '\n';
      }
}