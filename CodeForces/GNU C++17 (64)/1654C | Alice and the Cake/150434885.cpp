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
            int64_t sum = 0;
            vector <int64_t> a;
            for (int i = 0; i < n; ++i) {
                  int x; cin >> x;
                  sum += x;
                  a.push_back(x);
            }
            multiset <int64_t> ms(a.begin(), a.end());
            int ct = 0;
            bool ok = true;
            a.clear();
            a.push_back(sum);
            while (!a.empty()) {
                  int64_t mx = a.back();
                  a.pop_back();
                  if (ms.find(mx) != ms.end()) ms.erase(ms.find(mx));
                  else {
                        if (ct >= n || mx < 2) ok = false;
                        else {
                              a.push_back(mx / 2);
                              a.push_back((mx + 1) / 2);
                              ++ct;
                        }
                  }
            }
            cout << (ok ? "YES\n" : "NO\n");
      }
}