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
 
      vector <int> ded;
      int st = 1;
      while ((int) ded.size() <= 1000) {
            if (st % 3 == 0 || st % 10 == 3) st++;
            else ded.emplace_back(st), st++;
      }
 
      int t; cin >> t;
      while (t--) {
            int k; cin >> k; 
            cout << ded[k - 1] << '\n';
      }
}