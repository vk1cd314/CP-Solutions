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
 
      vector <string> v;
      for (char c = 'a'; c <= 'z'; ++c) {
            for (char d = 'a'; d <= 'z'; ++d) {
                  if (c == d) continue;
                  string tmp(1, c);
                  tmp += d;
                  v.push_back(tmp);
            }
      } 
      sort(v.begin(), v.end());
      int t; cin >> t;
      while (t--) {
            string s; cin >> s;
            cout << (lower_bound(v.begin(), v.end(), s) - v.begin()) + 1 << '\n';
      }
}