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
            vector <pair <int, int>> b(n); 
            for (int i = 0; i < n; ++i) {
                  cin >> b[i].first;
                  b[i].second = i;
            }
            sort(b.begin(), b.end());
            debug(b);
            int i = 0, j = 0;
            while (i < n) {
                  if (b[i].first == j) {
                        i++;
                        continue;
                  } else {
                        b[i].first = j++;
                  }
                  ++i;
            }
            sort(b.begin(), b.end(), [&](auto i, auto j) {
                  return i.second < j.second;
            });
            for (auto [x, i] : b) cout << x << ' ';
            cout << '\n';
      }
}