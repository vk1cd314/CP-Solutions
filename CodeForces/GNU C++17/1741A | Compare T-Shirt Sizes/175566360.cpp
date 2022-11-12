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
            string a, b; cin >> a >> b;
            char aa = a.back(), bb = b.back();
            if (aa == 'S') {
                  if (bb == 'M' || bb == 'L') cout << "<";
                  else {
                        int xa = count(a.begin(), a.end(), 'X');
                        int xb = count(b.begin(), b.end(), 'X');
                        if (xa == xb) cout << "=";
                        else if (xa > xb) cout << "<";
                        else cout << ">";
                  }
            } else if (aa == 'M') {
                  if (bb == 'S') cout << ">";
                  else if (bb == 'L') cout << "<";
                  else {
                        int xa = count(a.begin(), a.end(), 'X');
                        int xb = count(b.begin(), b.end(), 'X');
                        if (xa == xb) cout << "=";
                        else if (xa > xb) cout << ">";
                        else cout << "<";
                  }
            } else if (aa == 'L') {
                  if (bb == 'S' || bb == 'M') cout << ">";
                  else {
                        int xa = count(a.begin(), a.end(), 'X');
                        int xb = count(b.begin(), b.end(), 'X');
                        if (xa == xb) cout << "=";
                        else if (xa > xb) cout << ">";
                        else cout << "<";
                  }
            }
            cout << '\n';
      }
}