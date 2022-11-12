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

      int64_t l; cin >> l;
      int q; cin >> q;
      set <int> cut;
      cut.insert(0);
      cut.insert(l);
      while (q--) {
            int c; cin >> c;
            if (c == 1) {
                  int x; cin >> x;
                  cut.insert(x);
            } else {
                  int x; cin >> x;
                  if ((int) cut.size() == 2) {
                        cout << l << '\n';
                        continue;
                  }
                  auto it = cut.lower_bound(x);
                  cout << *it - *prev(it) << '\n';
            }
      }
}