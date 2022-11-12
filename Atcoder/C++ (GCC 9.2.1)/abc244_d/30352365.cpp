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

      string s(3, '0'); cin >> s[0] >> s[1] >> s[2];
      string t(3, '0'); cin >> t[0] >> t[1] >> t[2];

      vector <bool> eq(3, false);
      for (int i = 0; i < 3; ++i) eq[i] = s[i] == t[i];
      int ct = count(eq.begin(), eq.end(), false);
      assert(ct != 1);
      cout << (ct == 2 ? "No\n" : "Yes\n");
}