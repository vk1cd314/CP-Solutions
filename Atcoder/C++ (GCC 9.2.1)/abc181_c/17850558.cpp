#include <bits/stdc++.h>

using namespace std;

#ifdef BOI
#include "debug.h"
#else
#define debug(args...)
#endif

int main() {
      ios_base :: sync_with_stdio(0);
      cin.tie(0);

      int n; cin >> n;
      vector <pair <int, int>> a(n); 
      for (auto& f : a) cin >> f.first >> f.second;

      sort(a.begin(), a.end());
      bool ok = false;
      for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                  for (int k = j + 1; k < n; ++k) {
                        if ((a[j].second - a[i].second) * (a[k].first - a[j].first) == (a[k].second - a[j].second) * (a[j].first - a[i].first)) {
                              ok = true;
                              break;
                        }
                  }
                  if (ok) break;
            }
            if (ok) break;
      }      

      cout << (ok ? "Yes" : "No");
}
