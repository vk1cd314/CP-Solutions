#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
using namespace std;
set <int64_t> ss, ss1;
int64_t a, c1, c2;
string s;
 
void rec() {
      if ((int) s.size() > 10) return;
      if (s.empty()) a = 0;
      else a = stoll(s);
      ss.insert(a);
      s.push_back(char('0' + c1));
      rec();
      s.pop_back();
      s.push_back(char('0' + c2));
      rec();
      s.pop_back();
}
 
int main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
 
      for (int i = 0; i < 10; ++i) {
            for (int j = i + 1; j < 10; ++j) {
                  s.clear();
                  c1 = i, c2 = j;
                  rec();
            }
      }
 
      for (int i = 0; i < 10; ++i) {
            string nw = "";
            nw += char('0' + i);
            ss1.insert(stoll(nw));
            for (int j = 1; j < 11; ++j) {
                  nw += char('0' + i);
                  ss1.insert(stoll(nw));
            }
      }
 
      int t; cin >> t;
      while (t--) {
            int64_t n, k; cin >> n >> k;
            if (k == 1) cout << *ss1.lower_bound(n) << '\n';
            else cout << *ss.lower_bound(n) << '\n';
      }
}