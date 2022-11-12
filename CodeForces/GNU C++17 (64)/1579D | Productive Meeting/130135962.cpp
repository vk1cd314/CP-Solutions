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
            vector <pair <int, int>> a(n); 
            for (int i = 0; i < n; ++i) {
                  cin >> a[i].first;
                  a[i].second = i;
            }
            sort(a.begin(), a.end());
            vector <pair <int, int>> ids;
            priority_queue <pair <int, int>> pq;
            for (auto p : a) if (p.first != 0) pq.push(p);
            while (!pq.empty()) {
                  auto [v, id] = pq.top();
                  pq.pop();
                  if (pq.empty()) break;
                  auto [v1, id1] = pq.top(); pq.pop();
                  ids.push_back({id + 1, id1 + 1});
                  if (v - 1 > 0) pq.push({v - 1, id}); 
                  if (v1 - 1 > 0) pq.push({v1 - 1, id1});
                  debug(pq);
            }
            cout << ids.size() << '\n';
            for (auto [i, j] : ids) cout << i << ' ' << j << '\n';
      }
}