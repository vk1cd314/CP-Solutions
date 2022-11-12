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
 
            int n = s.size();
            map <char, int> pre, suff;
            for (int i = 0; i < n; ++i) suff[s[i]]++;
            string rem = "";
 
            for (int i = 0; i < n; ++i) {
                  pre[s[i]]++;
                  suff[s[i]]--;
                  if (pre[s[i]] > 0 && suff[s[i]] == 0) {
                        rem += s[i];
                  }
            }
 
            string ss = "";
            int len = 0;
            for (int i = 0; i < (int) rem.size(); ++i) len += pre[rem[i]] / (i + 1);
 
            if (len > n) {
                  cout << "-1\n";
                  continue;
            }
 
            ss = s.substr(0, len);
            string tmp = ss;
            map <char, bool> ok;
            for (char c : rem) ok[c] = true;
            for (char c1 : rem) {
                  ok[c1] = false;
                  for (char c2 : ss) {
                        if (ok[c2]) tmp += c2;
                  }
            }
 
            if (s != tmp) {
                  cout << "-1\n";
                  continue;
            }
 
            cout << ss << ' ' << rem << '\n';
      }
}