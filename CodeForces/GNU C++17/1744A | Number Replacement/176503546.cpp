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
            string s; cin >> s;
            map <int, char> mp;
            bool ok = true;
            for (int i = 0; i < n; ++i) {
                  if (!mp.count(a[i])) {
                        mp[a[i]] = s[i];
                  } else {
                        if (mp[a[i]] != s[i]) ok = false;
                  }
            }
            cout <<(ok ? "YES\n" : "NO\n");
      }
}