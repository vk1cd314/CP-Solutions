#include <bits/stdc++.h>

using namespace std;

#ifdef BOI
#include "debug.h"
#else
#define debug(args...)
#endif

int main() {
      ios_base :: sync_with_stdio(0);
      cin.tie(0);

      long long s, p; cin >> s >> p;
      vector <long long> facs;
      for (long long i = 1; i * i <= p; ++i) {
            if (p % i == 0) {
                  facs.push_back(i);
                  if (p / i != i) facs.push_back(p / i);
            }
      } 

      bool ok = false;
      for (auto x : facs) {
            if (x + p / x == s) {
                  ok = true;
                  break;
            }
      }

      if (ok) cout << "Yes";
      else cout << "No";
}

