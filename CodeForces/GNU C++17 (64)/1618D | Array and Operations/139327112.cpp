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
            int n, k; cin >> n >> k;
            vector <int> a(n);
            for (auto &x : a) cin >> x;
            sort(a.begin(), a.end());
            debug(a);
            int ans = 0;
            for (int i = 0; i < n - 2 * k; ++i) ans += a[i];
            vector <int> a1, a2;
            while (a1.size() != k) a1.push_back(a.back()), a.pop_back();
            while (a2.size() != k) a2.push_back(a.back()), a.pop_back();
            for (int i = 0; i < k; ++i) ans += a2[i] / a1[i]; 
            cout << ans << '\n';
      }
}