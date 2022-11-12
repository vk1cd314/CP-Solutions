#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
using namespace std;
 
int main() {
      #ifdef Icry
            auto begin = chrono::high_resolution_clock::now();
      #endif
      ios_base::sync_with_stdio(0);
      cin.tie(0);
 
      int t; cin >> t;
      while (t--) {
            int n, k; cin >> n >> k;
            vector <int> a(n); for (int &x : a) cin >> x;
            map <int, vector <int>> ids;
            for (int i = 0; i < n; ++i) {
                  ids[a[i]].push_back(i);
            }
 
            vector <int> ans(n);
            vector <pair <int, int>> ext;
            for (auto [x, v] : ids) {
                  if ((int)v.size() >= k) {
                        for (int i = 0; i < k; ++i) ans[v[i]] = i + 1;
                  } else {
                        for (int xx : v) {
                              ext.push_back({x, xx});
                        }
                  }
            }
 
            while ((int)ext.size() % k != 0) ext.pop_back();
 
            int col = 0;
            for (auto [x, y] : ext) ans[y] = col % k + 1, col++;
 
            for (int x : ans) cout << x << ' ';
            cout << '\n'; 
      }
 
      #ifdef Icry
            auto end = chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << chrono::duration_cast <chrono :: duration <double>> (end - begin).count() << " seconds]\n";  
      #endif
}