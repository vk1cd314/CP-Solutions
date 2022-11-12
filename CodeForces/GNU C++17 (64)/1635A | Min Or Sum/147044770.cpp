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
            vector <int64_t> a(n); for (auto &x : a) cin >> x;
            int64_t lol = accumulate(a.begin(), a.end(), 0LL);
            vector <int> bits(31);
            for (int i = 0; i < n; ++i) {
                  for (int j = 0; j < 31; ++j) {
                        if (a[i] & 1LL << j) bits[j]++;
                  }
            }
            for (int i = 0; i < 31; ++i) {
                  if (bits[i] < 2) continue;
                  lol -= (1LL << i) * (bits[i] - 1);
            }
            cout << lol << '\n';
      }
}