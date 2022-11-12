#include <bits/stdc++.h>
 
using namespace std;
 
#ifdef SENDHELP
#include "debug.h"
#else
#define debug(args...)
#endif
 
int main() {
      #ifdef SENDHELP
            auto begin = std::chrono::high_resolution_clock::now();
      #endif
      ios_base :: sync_with_stdio(0);
      cin.tie(0);
 
      int t; cin >> t;
      while (t--) {
            int n; cin >> n;
            vector <int> p(n); for (int& x : p) cin >> x;
            vector <pair <int, int>> ff;
            for (int i = 0; i < n; ++i) ff.push_back({p[i], i});
 
            sort(ff.begin(), ff.end(), [&](pair <int, int>& a, pair <int, int>& b) {
                  if (a.first == b.first) return a.second > b.second;
                  return a.first > b.first;
            });
 
            int now = -1;
            vector <int> order;
            for (int i = 0; i < n; ++i) {
                  if (order.empty()) order.push_back({ff[i].second});
                  else if (order.back() > ff[i].second) order.push_back(ff[i].second);
            }
 
            debug(order);
            vector <int> ans;
            int prev = n - 1;
            for (int i = 0; i < (int) order.size(); ++i) {
                  for (int j = order[i]; j <= prev;++j) {
                        ans.push_back(p[j]);
                  }
                  prev = order[i] - 1;
            }
            debug(ans);
            for (int x : ans) cout << x << ' ';
            cout << '\n';
      }
 
      #ifdef SENDHELP
            auto end = std::chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << std::chrono::duration_cast <std::chrono::duration <double>>(end - begin).count() << " seconds]\n";  
      #endif
}