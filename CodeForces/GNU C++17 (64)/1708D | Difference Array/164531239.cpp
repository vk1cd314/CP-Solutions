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
            assert(is_sorted(a.begin(), a.end()));
            // sort(a.begin(), a.end());
            vector <int> old_a = a;
            int ans = -1;
            int zeros = count(a.begin(), a.end(), 0);
            bool idkman = true;
            if (zeros == n) {
                  // cout << "0\n";
                  // continue;
                  ans = 0;
                  idkman = false;
            }
 
            debug(n, a);
            int tmp = zeros;
            reverse(a.begin(), a.end());
            while (tmp--) a.pop_back();
            reverse(a.begin(), a.end());
            while (idkman) {
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
                  if (!zeros) zeros = ze;
                  else zeros = max(zeros - 1 + ze, 0);
                  sort(nw.begin(), nw.end());
                  a = nw;
                  // debug(zeros, a);
            }
            auto brute = [&]() {
                  vector <int> lol = old_a;
                  while ((int) lol.size() != 1) {
                        vector <int> nw;
                        int sz = lol.size();
                        for (int i = 0; i + 1 < sz; ++i) {
                              nw.push_back(lol[i + 1] - lol[i]);
                        }
                        sort(nw.begin(), nw.end());
                        lol = nw;
                  }
                  return lol[0];
            };
 
            // int br = brute();
            // if (br != ans) {
            //       debug(br, ans);
            //       debug(n, old_a);
            //       // cout << n << '\n';
            //       // for (int x : old_a) cout << x << ' ';
            //       // cout << '\n';
            //       assert(false);
            // }
            cout << ans << '\n';
      }
}