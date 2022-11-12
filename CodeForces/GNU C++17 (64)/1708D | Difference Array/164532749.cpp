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
            int n; cin >> n;
            vector <int> a(n); for (int &x : a) cin >> x;
            int ans = -1;
            int zeros = count(a.begin(), a.end(), 0);
            if (zeros == n) {
                  cout << "0\n";
                  continue;
            }
            int tmp = zeros;
            reverse(a.begin(), a.end());
            while (tmp--) a.pop_back();
            reverse(a.begin(), a.end());
            while (true) {
                  vector <int> nw;
                  int sz = a.size();
                  if (sz == 1) {
                        ans = a[0];
                        break;
                  }
                  int ze = 0;
                  for (int i = 0; i + 1 < sz; ++i) {
                        if (a[i + 1] - a[i] == 0) ze++;
                        else nw.push_back(a[i + 1] - a[i]);
                  }
                  if (zeros) nw.push_back(a[0]);
                  if ((int) nw.size() == 0) {
                        ans = 0;
                        break;
                  }
                  zeros = max(zeros - 1, 0) + ze;
                  sort(nw.begin(), nw.end());
                  a = nw;
                  debug(a);
            }
            cout << ans << '\n';
      }
}