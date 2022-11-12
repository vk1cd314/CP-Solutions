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
            auto brute = [&]() {
                  vector <int> a(n);
                  double mn = LLONG_MAX;
                  iota(a.begin(), a.end(), 1);
                  map <double, vector <vector <int>>> mp;
                  do {
                        double cc = 0;
                        for (int i = 0; i + 2 < n; ++i) {
                              cc += (a[i] + a[i + 1] + a[i + 2]) / 3.0;
                        }
                        mn = min(mn, cc);
                        mp[cc].push_back(a);
                        // debug(cc, a);
                  } while (next_permutation(a.begin(), a.end()));
                  debug(mn);
                  debug(mp[mn], mp[mn].size());
            };
            // brute();
            vector <int> a(n);
            int i = 0, j = n - 1, curr = n;
            bool tt = true;
            while (i <= j) {
                  if (tt) a[j--] = curr--;
                  else a[i++] = curr--;
                  tt ^= 1;
            }
            int p1 = find(a.begin(), a.end(), 1) - a.begin();
            int p2 = find(a.begin(), a.end(), 2) - a.begin();
            int p3 = find(a.begin(), a.end(), 3) - a.begin();
            int mn = min({p1, p2, p3}), mx = max({p1, p2, p3});
            sort(a.begin() + mn, a.begin() + mx + 1);
            double mmn = LLONG_MAX;
            vector <int> res;
            do {  
                  debug(a);
                  double cc = 0;
                  for (int i = 0; i + 2 < n; ++i) {
                        cc += (a[i] + a[i + 1] + a[i + 2]) / 3.0;
                  }
                  if (cc < mmn) {
                        mmn = cc;
                        res = a;
                  }
            } while (next_permutation(a.begin() + mn, a.begin() + mx + 1));

            for (int x : res) cout << x << ' ';
            cout << '\n';
      }
}