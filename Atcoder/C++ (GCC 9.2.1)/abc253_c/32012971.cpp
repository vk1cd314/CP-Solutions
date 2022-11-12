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

      map <int, int> mp;
      int q; cin >> q;
      while (q--) {
            int t; cin >> t;
            if (t == 1) {
                  int x; cin >> x;
                  mp[x]++;
            } 
            if (t == 2) {
                  int x, c; cin >> x >> c;
                  mp[x] -= min(c, mp[x]);
                  if (mp[x] == 0) mp.erase(x);
            } 
            if (t == 3) {
                  cout << (*mp.rbegin()).first - (*mp.begin()).first << '\n';
            }
      }
}