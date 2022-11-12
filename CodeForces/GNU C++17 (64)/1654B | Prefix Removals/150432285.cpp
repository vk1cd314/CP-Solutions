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
            map <char, int> mp;
            for (char c : s) mp[c]++;
            int del = 0;
            for (int i = 0; i < (int) s.size(); ++i) {
                  if (!mp[s[i]]) continue;
                  mp[s[i]]--;
                  if (mp[s[i]]) del++;
                  else break;
            }
            cout << s.substr(del) << '\n';
      }
}