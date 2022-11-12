#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
using namespace std;
 
int main() {
      #ifdef Icry
            auto begin = std::chrono::high_resolution_clock::now();
      #endif
      ios_base :: sync_with_stdio(0);
      cin.tie(0);
 
      int t; cin >> t;
      while (t--) {
            int n; cin >> n;
            vector <string> gr(n); for (auto &s : gr) cin >> s;
            pair <int, int> one = {-1, -1}, two = {-1, -1};
            for (int i = 0; i < n; ++i) {
                  for (int j = 0; j < n; ++j) {
                        if (gr[i][j] == '*') {
                              if (one == make_pair(-1, -1)) one = {i, j};
                              else two = {i, j};
                        }
                  }
            }
 
            if (one.first == two.first) {
                  if (one.first == n - 1) {
                        gr[0][one.second] = '*';
                        gr[0][two.second] = '*';
                  } else {
                        gr[n - 1][one.second] = '*';
                        gr[n - 1][two.second] = '*';
                  }
            } else if (one.second == two.second) {
                  if (one.second == n - 1) {
                        gr[one.first][0] = '*';
                        gr[two.first][0] = '*';
                  } else {
                        gr[one.first][n - 1] = '*';
                        gr[two.first][n - 1] = '*';
                  }
            } else {
                  gr[one.first][two.second] = '*';
                  gr[two.first][one.second] = '*';
            }
 
            for (auto s : gr) cout << s << '\n';
            // cout << '\n';
      }
 
      #ifdef Icry
            auto end = std::chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << std::chrono::duration_cast <std::chrono::duration <double>>(end - begin).count() << " seconds]\n";  
      #endif
}