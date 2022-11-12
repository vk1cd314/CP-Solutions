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

      int a, b, c; cin >> a >> b >> c;
      if (a > c) swap(a, c);
      cout << (a <= b && b <= c ? "Yes\n" : "No\n");
}