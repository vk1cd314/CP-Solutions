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
            string w; cin >> w;
            int p; cin >> p;
            int n = w.size();
            vector <int> bye(n, 1);
            priority_queue <pair <char, int>> pq;
            int cost = 0;
            for (int i = 0; i < n; ++i) pq.push({w[i], i}), cost += (w[i] - 'a') + 1;
            int rem = 0;
            debug(cost);
            while (cost > p) {
                  auto tp = pq.top(); pq.pop();
                  debug(tp);
                  cost -= tp.first - 'a' + 1;
                  bye[tp.second] = 0;
                  ++rem;
            }
            debug(cost);
            for (int i = 0; i < n; ++i) {
                  if (bye[i]) cout << w[i];
            }
            cout << '\n';
      }
}