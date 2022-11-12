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
            map <string, int> mp;
            string ret(n, '0');
            vector <string> v;
            for (int i = 0; i < n; ++i) {
                  string s; cin >> s; 
                  v.push_back(s);
                  mp[s]++;
            }
            for (int i = 0; i < n; ++i) {
                  string s1 = "", s2 = v[i];
                  int sz = v[i].size();
                  bool ok = false;
                  for (int j = 0; j < sz; ++j) {
                        if (mp[s1] && mp[s2]) ok = true;
                        s1.push_back(v[i][j]);
                        s2.erase(s2.begin());
                  }
                  if (ok) ret[i] = '1';
            }
            cout << ret << '\n';
      }
}