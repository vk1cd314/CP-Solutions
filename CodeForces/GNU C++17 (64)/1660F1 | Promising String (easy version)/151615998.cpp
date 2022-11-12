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
            string s; cin >> s;
            vector <int> pre(n);
            pre[0] = s[0] == '+' ? 1 : -1;
            for (int i = 1; i < n; ++i) {
                  pre[i] = pre[i - 1];
                  pre[i] += s[i] == '+' ? 1 : -1;
            }  
 
            int ans = 0;
            for (int i = 0; i < n; ++i) {
                  for (int j = i; j < n; ++j) {
                        int cnt = pre[j] - (i ? pre[i - 1] : 0);
                        ans += cnt <= 0 && cnt % 3 == 0;
                  }
            }
            cout << ans << '\n';
      }
}