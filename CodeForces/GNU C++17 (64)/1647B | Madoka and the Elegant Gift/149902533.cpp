#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
 
      int t; cin >> t;
      while (t--) {
            int n, m; cin >> n >> m;
            vector <string> mat(n);
            for (int i = 0; i < n; ++i) cin >> mat[i];
            vector <set <pair <int, int>>> conn;
            vector <vector <bool>> vis(n, vector <bool>(m, false));
            set <pair <int, int>> tmp;
            int dx[4] = {0, 1, -1, 0};
            int dy[4] = {1, 0, 0, -1};
            auto good = [&](int i, int j) {
                  return (0 <= i && i < n && 0 <= j && j < m);
            };
            function <void(int, int)> dfs = [&](int i, int j) {
                  vis[i][j] = true;
                  tmp.insert({i, j});
                  for (int k = 0; k < 4; ++k) {
                        int xx = i + dx[k], yy = j + dy[k];
                        if (good(xx, yy) && !vis[xx][yy] && mat[xx][yy] == '1') dfs(xx, yy);
                  }
            };
            for (int i = 0; i < n; ++i) {
                  for (int j = 0; j < m; ++j) {
                        if (!vis[i][j] && mat[i][j] == '1') {
                              tmp.clear();
                              dfs(i, j);
                              conn.push_back(tmp);
                        }
                  }
            }
            bool ok = true;
            for (auto s : conn) {
                  pair <int, int> st = *s.begin();
                  pair <int, int> ed = *s.rbegin();
                  // cout << st.first << ' ' << st.second << '\n';
                  // cout << ed.first << ' ' << ed.second << '\n';
                  int l1 = abs(st.first - ed.first) + 1, l2 = abs(st.second - ed.second) + 1;
                  ok &= l1 * l2 == (int) s.size();
                  for (int i = min(st.first, ed.first); i <= max(st.first, ed.first); ++i) {
                        for (int j = min(st.second, ed.second); j <= max(st.second, ed.second); ++j) ok &= s.count({i, j});
                  }
            }
            cout << (ok ? "YES\n" : "NO\n");
      }
}