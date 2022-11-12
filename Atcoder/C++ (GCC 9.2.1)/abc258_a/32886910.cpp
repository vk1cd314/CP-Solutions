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

      int k; cin >> k;
      if (k < 60) {
            cout << "21:";
            if (k < 10) cout << "0" << k;
            else cout << k;
      } else {
            k %= 60;
            cout << "22:";
            if (k < 10) cout << "0" << k;
            else cout << k;
      }
}