#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...)
#endif
 
using namespace std;
 
const int N = 2e5 + 10;
int dp[N], a[N], par[N], n;
map <int, vector <int>> id;
map <int, vector <pair <int, int>>> sa;
 
int main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
 
      cin >> n;
      for (int i = 0; i < n; ++i) {
            cin >> a[i];
            id[a[i]].push_back(i);
      }
      for (auto [val, v] : id) sa[val].resize(v.size());      
      for (int i = 0; i < n; ++i) dp[i] = 1;
      iota(par, par + N, 0);
      int mx = -1;
      int idb = -1;
      for (int i = n - 1; i >= 0; --i) {
            auto it1 = lower_bound(id[a[i]].begin(), id[a[i]].end(), i);
            int pos = it1 - id[a[i]].begin(); 
            int sz2 = id[a[i]].size();
            if (pos == sz2 - 1) sa[a[i]][pos] = {dp[i], i};
            else sa[a[i]][pos] = sa[a[i]][pos + 1];
            if (dp[i] > mx) {
                  mx = dp[i];
                  idb = i;
            }
            if (!id.count(a[i] + 1)) continue;
            int nMax = 0, nIdb = -1;
            auto it = lower_bound(id[a[i] + 1].begin(), id[a[i] + 1].end(), i);
            if (it == id[a[i] + 1].end()) continue;
            int stId = it - id[a[i] + 1].begin();
            // assert(stId > i);
            tie(nMax, nIdb) = sa[a[i] + 1][stId];
            assert(nIdb != -1);
            par[i] = nIdb;
            dp[i] += nMax;
            if (dp[i] > sa[a[i]][pos].first) {
                  sa[a[i]][pos] = {dp[i], i};
            }
            if (dp[i] > mx) {
                  mx = dp[i];
                  idb = i;
            }
      }
 
      debug(mx, idb);
      vector<int> res;
      res.push_back(idb + 1);
      while (par[idb] != idb) {
            idb = par[idb];
            res.push_back(idb + 1);
      }
      debug(mx);
      debug(res);
      cout << mx << '\n';
      for (int x : res) cout << x << ' ';
      cout << '\n';
}