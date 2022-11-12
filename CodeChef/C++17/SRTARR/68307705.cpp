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
            string s; cin >> s;
            if (is_sorted(s.begin(), s.end())) cout << "0\n";
            else {
                  vector <pair <char, int>> a;
                  a.push_back({s[0], 1});
                  for (int i = 1; i < n; ++i) {
                        if (a.back().first == s[i]) a.back().second++;
                        else a.push_back({s[i], 1});
                  } 
                  int ct = 0;
                  int sz = a.size();
                  for (int i = 0; i < sz; ++i) if (a[i].first == '1') ++ct;
                  if (a[sz - 1].first == '1') --ct;
                  cout << ct << '\n';
            }
      }
}