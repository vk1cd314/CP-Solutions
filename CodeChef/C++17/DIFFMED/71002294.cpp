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
            vector <int> a(n);
            int l = 0, r = 0;
            // for (int i = 0; i + 1 < n; i += 2) {
            //       a[i] = l++;
            //       a[i + 1] = r++;
            // }
            // a[n - 1] = n;
            for (int i = 1; i < n; ++i) {
                  if (i % 2) a[i] = --l;
                  else a[i] = ++r;
            }
            for (int i = 0; i < n; ++i) a[i] += -l + 1;
            vector <int> prv, curr;
            curr.push_back(a[0]);
            bool ok = true;
            for (int i = 0; i + 1 < n; ++i) {
                  if (!prv.empty()) {
                        sort(prv.begin(), prv.end());
                        sort(curr.begin(), curr.end());
                        int sz1 = prv.size(), sz2 = curr.size();
                        assert(sz1 + 1 == sz2);
                        ok &= (prv[(sz1 - 1) / 2] != curr[(sz2 - 1) / 2]);
                  }
                  prv.push_back(a[i]);
                  curr.push_back(a[i + 1]);
            }
            assert(ok);
            for (int x : a) cout << x << ' ';
            cout << '\n';
      }
}