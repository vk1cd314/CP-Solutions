#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
 
      int t; cin >> t;
      while (t--) {
            int n; cin >> n;
            if (n < 3) {
                  cout << n << '\n';
                  continue;
            }
            string s, s1;
            int nn = n - 2;
            n -= 1;
            s += '1';
            bool nops = false, nops1 = false;
            while (n) {
                  if (s.back() == '1') {
                        if (n == 1) nops = true, n = 0;
                        else n -= 2, s += '2';
                  } else {
                        s += '1';
                        n -= 1;
                  }
            }
            s1 += '2';
            while (nn) {
                  if (s1.back() == '1') {
                        if (nn == 1) nops1 = true, nn = 0;
                        else nn -= 2, s1 += '2';
                  } else {
                        s1 += '1';
                        nn -= 1;
                  }
            }
 
            if (!nops && !nops1) {
                  if (s.size() > s1.size()) cout << s << '\n';
                  else cout << s1 << '\n';
            } else if (!nops) {
                  cout << s << '\n';
            } else cout << s1 << '\n';
      }
}