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
            vector <int> a(n); for (int &x : a) cin >> x, x %= 10;
            vector <int> lo[10];
            for (int i = 0; i < n; ++i) {
                  lo[a[i]].push_back(i);
            }
            bool ok = false;
            for (int i = 0; i < 10 && !ok; ++i) {
                  for (int j = 0; j < 10 && !ok; ++j) {
                        for (int k = 0; k < 10 && !ok; ++k) {
                              if ((i + j + k) % 10 == 3) {
                                    int s1 = (int) lo[i].size();
                                    int s2 = (int) lo[j].size();
                                    int s3 = (int) lo[k].size();
                                    if (i == j && j == k) {
                                          if (s1 > 2) ok = true;
                                    } else if (i == j) {
                                          if (s1 > 1 && s3 > 0) ok = true;
                                    } else if (j == k) {
                                          if (s1 > 0 && s2 > 1) ok = true;
                                    } else if (i == k) {
                                          if (s1 > 1 && s2 > 0) ok = true;
                                    } else if (s1 > 0 && s2 > 0 && s3 > 0) ok = true;
                              }
                        }
                  }
            }
            cout << (ok ? "YES\n" : "NO\n");
      }
}