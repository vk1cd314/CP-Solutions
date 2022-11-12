#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
using namespace std;
 
const int64_t dd = 1e18 + 10;
 
int main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
 
      vector <int64_t> p2;
      int64_t pp = 1;
      while (pp < dd) p2.emplace_back(pp), pp *= 2LL;
 
      // debug(p2);
      int t; cin >> t;
      while (t--) {
            string s; cin >> s;
 
            auto cnt = [&](string &s, int64_t ded) {
                  string nw = to_string(ded);
                  int j = 0;
                  for (char c : s) {
                        if (j < (int) nw.size() && c == nw[j]) j++; 
                  }
                  return j;
            };
 
            int ans = INT_MAX;
            for (int64_t p : p2) {
                  int ct = cnt(s, p);
                  string ss = to_string(p);
                  int del = (int) s.size() - ct;
                  int add = (int) ss.size() - ct;
                  // debug(p, del, add);
                  ans = min(ans, del + add);
            }
 
            cout << ans << '\n';
      }
}