#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
using namespace std;
 
const int N = 2e5 + 10;
vector <int> g[N];
vector <pair <int, int>> leaves;
 
void dfs(int u, int p, int d = 0) {
      int l = 0;
      for (int v : g[u]) {
            if (v != p) dfs(v, u, d + 1), l++;
      }
      if (!l) leaves.push_back({d, u});
}
 
int main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
 
      int t; cin >>t;
      while (t--) {
            int n; cin >> n;
            for (int i = 0; i <= n; ++i) g[i].clear();
            int root = -1;
            vector <int> p; p.push_back(0);
            for (int i = 0; i < n; ++i) {
                  int x; cin >> x;
                  p.push_back(x);
                  if (x == i + 1) root = x;
                  g[x].push_back(i + 1);
                  g[i + 1].push_back(x);
            }
            leaves.clear();
            dfs(root, -1, 0);
            sort(leaves.rbegin(), leaves.rend());
            vector <int> vis(n + 1);
            vector <vector <int>> ans;
            for (int i = 0; i < (int) leaves.size(); ++i) {
                  vector <int> v;
                  int val = leaves[i].second;
                  while (!vis[val]) {
                        v.push_back(val);
                        vis[val]++;
                        val = p[val];
                  }
                  if (!v.empty()) ans.push_back(v);
            }
            cout << ans.size() << '\n';
            for (auto &v : ans) {
                  cout << v.size() << '\n';
                  reverse(v.begin(), v.end());
                  for (int x : v) cout << x << ' ';
                  cout << '\n';
            }
            cout << '\n';
      }
}