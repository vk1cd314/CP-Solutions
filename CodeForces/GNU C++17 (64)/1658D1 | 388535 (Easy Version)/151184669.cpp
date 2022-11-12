#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
using namespace std;
 
const int N = (1 << 17) + 10;
int ct[N][20];
 
int main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
 
      for (int i = 1; i < N; ++i) {
            for (int j = 0; j < 20; ++j) {
                  ct[i][j] = ct[i - 1][j];
                  if (i & 1 << j) ct[i][j]++;
            }
      }
 
      int t; cin >> t;
      while (t--) {
            int l, r; cin >> l >> r;
            vector <int> a(r - l + 1);
            for (int &x : a) cin >> x;
            int mx = r - l;
            int mxbit = 0;
            int ans = 0;
            for (int i = 0; i < 20; ++i) {
                  if (mx & 1 << i) mxbit = i;
            }
            vector <vector <int>> cnt(r - l + 1, vector <int>(20));
            vector <int> done(20);
            for (int i = 0; i < r - l + 1; ++i) {
                  for (int j = 0; j < 20; ++j) {
                        if (i) cnt[i][j] = cnt[i - 1][j];
                        if (a[i] & 1 << j) {
                              if (done[j]) {
                                    a[i] ^= 1 << j;
                              }
                              else if (j > mxbit) {
                                    ans += 1 << j;
                                    a[i] ^= 1 << j;
                                    done[j]++;
                              } else cnt[i][j]++; 
                        }
                  }
            }
            // debug(cnt);
            for (int i = 0; i < 20; ++i) {
                  if (cnt[r - l][i] != ct[r - l][i]) ans += 1 << i;
            }
            cout << ans << '\n';
      }
}
// 11
// mxbit = 1