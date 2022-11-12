#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
using namespace std;
 
#define ll long long
 
int main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
 
      int t; cin >> t;
      while (t--) {
            int n; cin >> n;
            vector <ll> a(n + 1); 
            for (int i = 1; i <= n; ++i) cin >> a[i];
            map <int, vector <int>> g;
            for (int i = 1; i <= n; ++i) {
                  if (a[i] + i <= n) g[i].push_back(a[i] + i);
                  if (i - a[i] >= 1) g[i - a[i]].push_back(i);
            }
            vector <int> reachable(n + 2);
            reachable[1] = 1;
            for (int i = 1; i <= n; ++i) {
                  if (reachable[i]) {
                        for (int j : g[i]) reachable[j + 1] = 1;
                  }
            }
            bool ok = reachable[n + 1] > 0;
            cout << (ok ? "YES\n" : "NO\n");
      }
}