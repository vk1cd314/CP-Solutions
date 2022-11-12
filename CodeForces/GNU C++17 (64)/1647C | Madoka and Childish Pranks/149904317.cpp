#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
 
      int t; cin >> t;
      while (t--) {
            int n, m; cin >> n >> m;
            vector <string> a(n); for (auto &s : a) cin >> s;
            vector <tuple <int, int, int, int>> ans;
            if (a[0][0] == '1') cout << "-1\n";
            else {
                  for (int i = n - 1; i >= 0; --i) {
                        for (int j = m - 1; j >= 0; --j) {
                              if (a[i][j] == '1') {
                                    if (i) ans.push_back({i - 1, j, i, j});
                                    else ans.push_back({i, j - 1, i, j});
                              }
                        }
                  }
                  cout << ans.size() << '\n';
                  for (auto [i1, j1, i2, j2] : ans) {
                        cout << i1 + 1 << ' ' << j1 + 1 << ' ' << i2 + 1 << ' ' << j2 + 1 << '\n';
                  }
            }
      }
}