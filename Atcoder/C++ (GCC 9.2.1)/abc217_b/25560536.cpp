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

      set <string> ss;
      ss.insert("ABC");
      ss.insert("ARC");
      ss.insert("AGC");
      ss.insert("AHC");
      string s; cin >> s;
      ss.erase(s);
      cin >> s;
      ss.erase(s);
      cin >> s;
      ss.erase(s);
      cout << *ss.begin() << '\n';
}