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
            vector <int> a(n); for (int &x : a) cin >> x;
            vector <int> b = a;
            auto shift = [&](int l, int r, int d) {
                  vector <int> kek;
                  for (int i = l; i <= r; ++i) kek.push_back(a[i]);
                  int lst = kek.back();
                  kek.pop_back();
                  kek.insert(kek.begin(), lst);
                  debug(kek);
                  for (int i = l; i <= r; ++i) a[i] = kek[i - l];
            };
            sort(b.begin(), b.end());
            debug(b);
            vector <tuple <int, int, int>> pp;
            for (int i = 0; i < n; ++i) {
                  if (b[i] != a[i]) {
                        for (int j = i + 1; j < n; ++j) {
                              if (a[j] == b[i]) {
                                    shift(i, j, j - i);
                                    debug(a);
                                    pp.push_back({i + 1, j + 1, j - i});
                                    break;
                              }
                        }
                  }
            }
 
            assert((int) pp.size() <= n);
            cout << pp.size() << '\n';
            for (auto [l, r, d] : pp) cout << l << ' ' << r << ' ' << d << '\n';
      }
}