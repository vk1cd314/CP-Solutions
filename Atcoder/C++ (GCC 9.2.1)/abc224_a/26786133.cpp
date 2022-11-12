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

      string s; cin >> s;
      int sz = s.size();
      if (sz >= 3 && s[sz - 3] == 'i' && s[sz - 2] == 's' && s[sz - 1] == 't') {
            cout << "ist\n";
      } else if (s.size() >= 2  && s[sz - 2] == 'e' && s[sz - 1] == 'r') {
            cout << "er\n";
      }
}