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

      string a, b; cin >> a >> b;
      if (a < b) cout << "Yes\n";
      else cout << "No\n";
}