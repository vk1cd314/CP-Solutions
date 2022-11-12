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
            vector <int> ze;
            ze.push_back(-1);
            for (int i = 0; i < n; ++i) if (a[i] == 0) ze.push_back(i);
            ze.push_back(n);
            auto work = [&](int l, int r) {
                  if (l > r) return array <int, 3>{0, n, 0};
                  int neg = 0;
                  for (int i = l; i <= r; ++i) neg += a[i] < 0;
                  if (neg % 2 == 0) {
                        int cnt = 0;
                        for (int i = l; i <= r; ++i) cnt += a[i] == 2 || a[i] == -2;
                        return array <int, 3>{cnt, l, n - r - 1};
                  }
                  int f = -1, la = -1;
                  for (int i = r; i >= l; --i) if (a[i] < 0) f = i;
                  for (int i = l; i <= r; ++i) if (a[i] < 0) la = i;
                  int cnt1 = 0, cnt2 = 0;
                  for (int i = f + 1; i <= r; ++i) cnt1 += a[i] == 2 || a[i] == -2;
                  for (int i = l; i <= la - 1; ++i) cnt2 += a[i] == 2 || a[i] == -2;
                  if (cnt1 > cnt2) return array <int, 3>{cnt1, f + 1, n - r - 1};
                  return array <int, 3>{cnt2, l, n - la};
            };
 
            int curr = -1;
            pair <int, int> ans = {-1, -1};
            for (int i = 0; i + 1 < (int) ze.size(); ++i) {
                  auto ff = work(ze[i] + 1, ze[i + 1] - 1);
                  debug(ff);
                  if (ff[0] > curr) {
                        curr = ff[0];
                        ans = {ff[1], ff[2]};
                  }
            }
            cout << ans.first << ' ' << ans.second << '\n';
      }
}