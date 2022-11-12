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
 
      int n; cin >> n; n--;
      vector <string> t;
      string s; cin >> s;
      t.push_back(s);
      while (n--) {
            cin >> s;
            if (t.back() != s) t.push_back(s);
      }
      cout << (int) t.size() << '\n';
}