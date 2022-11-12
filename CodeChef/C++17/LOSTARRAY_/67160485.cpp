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
            vector <long long> b(n + 1);
            if (n & 1) {
                  long long shob = 0;
                  for (auto &x : b) cin >> x, shob ^= x;
                  long long tot = -1;
                  int id = -1;
                  for (int i = 0; i < n + 1; ++i) {
                        if ((shob ^ b[i]) == 0) {
                              tot = b[i];
                              id = i;
                              break;
                        }
                  }
                  for (int i = 0; i < n + 1; ++i) {
                        if (id != i) cout << (tot ^ b[i]) << ' ';
                  }
                  cout << '\n';
                  continue;
            }
            for (auto &x : b) cin >> x;
            long long tot = b[0];
            for (int i = 1; i < n + 1; ++i) {
                  cout << (tot ^ b[i]) << ' ';
            }
            cout << '\n';
      }
}