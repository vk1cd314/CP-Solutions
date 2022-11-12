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

      int n; cin >> n;
      string s; cin >> s;
      string p = "";
      for (int i = 0; i < n; ++i) {
            p.push_back(s[i]);
            bool ok = p.size() > 1;
            while (ok) {
                  int sz = p.size();
                  if (p[sz - 1] == 'B' && p[sz - 2] == 'B') {
                        p.pop_back();
                        p.pop_back();
                        p.push_back('A');
                  } else if (p[sz - 1] == 'A' && p[sz - 2] == 'B') {
                        swap(p[sz - 1], p[sz - 2]);
                  } else break;
                  ok = p.size() > 1;
            }
      }

      cout << p << '\n';
}