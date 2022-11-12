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
            int64_t n, m, i, j; cin >> n >> m >> i >> j;
 
            auto dist = [&](pair <int64_t, int64_t> &a, pair <int64_t, int64_t> &b) {
                  // i, j to a then to b
                  int64_t ret1 = abs(a.first - i) + abs(a.second - j) + abs(a.first - b.first) + abs(a.second - b.second);
                  // i, j to b then a
                  int64_t ret2 = abs(b.first - i) + abs(b.second - j) + abs(b.first - a.first) + abs(b.second - a.second);
                  return min(ret1, ret2);
            };
 
            vector <pair <int64_t, int64_t>> maybe;
            maybe.push_back({1, 1});
            maybe.push_back({n, 1});
            maybe.push_back({1, m});
            maybe.push_back({n, m});
 
            int64_t ans = -1;
            pair <int, int> a1 = {-1, -1};
            pair <int, int> a2 = {-1, -1};
            for (int i = 0; i < 4; ++i) {
                  for (int j = i + 1; j < 4; ++j) {
                        if (dist(maybe[i], maybe[j]) > ans) {
                              a1 = maybe[i];
                              a2 = maybe[j];
                              ans = dist(maybe[i], maybe[j]);
                        }
                  }
            }
            assert(a1 != make_pair(-1, -1));
            assert(a2 != make_pair(-1, -1));
 
            cout << a1.first << ' ' << a1.second << ' ';
            cout << a2.first << ' ' << a2.second << '\n';
      }
 
      #ifdef Icry
            auto end = chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << chrono::duration_cast <chrono :: duration <double>> (end - begin).count() << " seconds]\n";  
      #endif
}