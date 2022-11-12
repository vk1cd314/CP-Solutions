#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif

using namespace std;

const double PI = acos(-1);

int main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);

      string s, t; cin >> s >> t;
      
      auto compress = [&](string x) {
            vector <pair <int, int>> f;
            f.push_back({x[0], 1});
            for (int i = 1; i < (int) x.size(); ++i) {
                  if (f.back().first == x[i]) f.back().second++;
                  else {
                        f.push_back({x[i], 1});
                  }
            }
            return f;
      };

      auto f1 = compress(s);
      auto f2 = compress(t);
      debug(f1, f2);
      bool ok = true;
      if (f1.size() == f2.size()) {
            for (int i = 0; i < (int) f1.size(); ++i) {
                  if (f1[i].second == 1) {
                        if (f2[i].second != 1) ok = false;
                  }
                  ok &= (f1[i].first == f2[i].first) and (f1[i].second <= f2[i].second);
            }
            if (ok) cout << "Yes\n";
            else cout << "No\n";
      } else cout << "No\n";

}