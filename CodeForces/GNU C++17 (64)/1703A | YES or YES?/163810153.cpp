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
            string s; cin >> s;
            auto to_upper = [&](char c) {
                  if (c > 'Z') {
                        int p = c - 'a';
                        return char('A' + p);
                  } 
                  return c;
            };
            for (char &c : s) c = to_upper(c);
            cout << (s == "YES" ? "YES\n" : "NO\n");
      }
}