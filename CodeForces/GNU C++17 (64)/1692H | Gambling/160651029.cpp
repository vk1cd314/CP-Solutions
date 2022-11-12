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
            vector <long long> a(n); for (long long &x : a) cin >> x;
            map <long long, vector <int>> mp;
            for (int i = 0; i < n; ++i) {
                  mp[a[i]].push_back(i);
            }
            int ans = 1;
            int a1 = a.back(), l1 = n - 1, r1 = n - 1;
            debug(ans, a1, l1, r1);
            debug(mp);
            for (auto &[x, v] : mp) {
                  // if (v[0] != 0) v.insert(v.begin(), 0);
                  int st = v[0], ed = v[0], st_o = v[0];
                  long long curr_max = 1, prev_max = 1;
                  int sz = v.size();
                  for (int i = 1; i < sz; ++i) {
                        long long d = v[i];
                        d -= v[i - 1];
                        d--;
                        d = -d;
                        d++;
                        curr_max += d;
                        if (curr_max <= 0) {
                              st = v[i];
                              curr_max = 1;
                        } else if (curr_max > prev_max) {
                              ed = v[i];
                              st_o = st;
                              prev_max = curr_max;
                        }
                  }
                  if (prev_max > ans) {
                        debug(prev_max, x, st_o, ed);
                        ans = prev_max;
                        a1 = x;
                        l1 = st_o;
                        r1 = ed;
                  }
            }
            cout << a1 << ' ' << l1 + 1 << ' ' << r1 + 1 << '\n';
      }
}