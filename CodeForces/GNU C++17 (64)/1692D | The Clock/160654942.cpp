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
            int x; cin >> x;
            string h(1, s[0]); h += s[1];
            string t(1, s[3]); t += s[4];
            pair <int, int> curr = {stoi(h), stoi(t)};
            pair <int, int> tmp = curr;
            // debug(curr);
            auto nxt = [&](int xx) {
                  return make_pair((curr.first + xx / 60 + (curr.second + xx % 60 >= 60)) % 24, (curr.second + xx % 60) % 60);             
            };
            auto ispal = [&](pair <int, int> f) {
                  return f.first / 10 == f.second % 10 && f.first % 10 == f.second / 10;
            };
            set <pair <int, int>> ss;
            int lol = x;
            // debug(nxt(81));
            map <pair <int, int>, int> ff;
            while (1) {
                  // debug(tmp);
                  ff[tmp]++;
                  if (ispal(tmp)) ss.insert(tmp);
                  tmp = nxt(lol);
                  // debug(lol);
                  lol += x;
                  if (ff[tmp]) break;
            }
            // debug(ss);
            cout << ss.size() << '\n';
            // for (int i = 0; i < 24 * 60; ++i) {
            //       int h1 = i / 60, m1 = i % 60;
            //       pair <int, int> k = {h1, m1};
            //       int tim = abs(h1 - curr.first) * 60 + abs()
            // }
      }
}