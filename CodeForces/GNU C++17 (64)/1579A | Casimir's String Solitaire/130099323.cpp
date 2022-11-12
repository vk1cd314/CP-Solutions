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
            string s; cin >> s;
            int a = count(s.begin(), s.end(), 'A');
            int b = count(s.begin(), s.end(), 'B');
            int c = count(s.begin(), s.end(), 'C');
            if (a + c == b) cout << "YES\n";
            else cout << "NO\n";
      }
}