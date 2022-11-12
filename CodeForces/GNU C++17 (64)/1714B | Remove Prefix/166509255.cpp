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
            map <int, int> mp;
            vector <int> a(n); for (int &x : a) cin >> x, mp[x]++;
            int ans = 0;
            for (int i = 0; i < n; ++i) {
                  if ((int) mp.size() == n - i) break;
                  ans = i + 1;
                  mp[a[i]]--;
                  if (!mp[a[i]]) mp.erase(a[i]); 
            }
            cout << ans << '\n';
      }
}