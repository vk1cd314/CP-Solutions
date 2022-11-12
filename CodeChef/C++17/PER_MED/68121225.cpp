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
            // vector <int> a(n); iota(a.begin(), a.end(), 1);
            // do {
            //       bool ok = true;
            //       vector <int> pp; pp.push_back(a[0]);
            //       for (int i = 1; i < n; ++i) {
            //             pp.push_back(a[i]);
            //             sort(pp.begin(), pp.end());
            //             int sz = pp.size();
            //             int med = pp[(sz - 1) / 2];
            //             ok &= (med == a[i]);
            //       }
            //       if (ok) {
            //             debug(a);
            //       }
            // } while (next_permutation(a.begin(), a.end()));
            vector <int> a(n);
            int curr = n, i = 0;
            while (i < n) {
                  a[i] = curr;
                  curr--;
                  i += 2;
            }
            i = 1;
            curr = 1;
            while (i < n) {
                  a[i] = curr;
                  curr++;
                  i += 2;
            }
            for (int x : a) cout << x << ' ';
            cout << '\n';
      }
}