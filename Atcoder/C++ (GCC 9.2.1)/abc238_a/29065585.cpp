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

      int n; cin >> n;
      if (n == 2 || n == 3 || n == 4) cout << "No\n";
      else cout << "Yes\n";
}