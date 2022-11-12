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
            int s; cin >> s;
            vector <int> num;
            for (int i = 9; i >= 1; --i) {
                  if (s - i >= 0) num.push_back(i), s -= i;
            }
            sort(num.begin(), num.end());
            for (int x : num) cout << x;
            cout << '\n';
      }
}