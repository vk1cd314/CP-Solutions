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
            int n, k; cin >> n >> k;
            string s; cin >> s;
            vector <int> req(n);
            for (int i = 0; i < n; ++i) {
                  if (s[i] == '0') {
                        if (k % 2) req[i] = 0; // even 
                        else req[i] = 1; // odd
                  } else {
                        if (k % 2) req[i] = 1;
                        else req[i] = 0;
                  }
            }
            vector <int> ids0, ids1;
            for (int i = 0; i < n; ++i) {
                  if (req[i]) ids0.push_back(i);
                  else ids1.push_back(i);
            }
            // debug(ids0, ids1);
            int kk = k;
            vector <int> cnt(n);
            for (int i = 0; i < (int) ids0.size(); ++i) {
                  if (k) cnt[ids0[i]]++, --k;
            }
            if (k % 2 == 0) {
                  if (ids0.empty()) cnt[ids1.back()] = k;
                  else cnt[ids0.back()] += k;
            } else {
                  // if (ids1.empty()) cnt[ids0.back()] += k;
                  // else cnt[ids1.back()] += k;
                  cnt[n - 1] += k;
            }
            for (int i = 0; i < n; ++i) {
                  if ((kk - cnt[i]) % 2) cout << (s[i] == '1' ? '0' : '1');
                  else cout << s[i];
            }
            cout << '\n';
            for (int x : cnt) cout << x << ' ';
            cout << '\n';
 
      }
}