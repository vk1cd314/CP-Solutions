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
            long long a, b, n; cin >> a >> b >> n;
            vector <long long> need;
            for (int i = 0; i < 31; ++i) {
                  if ((a >> i & 1) != (b >> i & 1)) need.push_back(1 << i);
            }
            if (need.empty()) {
                  cout << "0\n";
                  continue;
            }
            if (need.back() >= n) {
                  cout << "-1\n";
                  continue;
            }
            int ops = 0;
            while (a != b) {
                  vector <long long> nw;
                  sort(need.rbegin(), need.rend());
                  long long take = 0;
                  for (int i = 0; i < (int) need.size(); ++i) {
                        if (take + need[i] < n) take += need[i];
                        else nw.push_back(need[i]);
                  }
                  a ^= take;
                  ++ops;
                  need = nw;
            }
            cout << ops << '\n';
      }
}