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
            vector <int> aa = a;
            sort(aa.begin(), aa.end());
            bool ok = true;
            for (int i = (n & 1 ? 1 : 0); i < n && ok; i += 2) {
                  vector <int> v1 = {a[i], a[i + 1]}, v2 = {aa[i], aa[i + 1]};
                  sort(v1.begin(), v1.end());
                  ok &= v1 == v2;
            }
            cout << (ok ? "YES\n" : "NO\n");
      }
}