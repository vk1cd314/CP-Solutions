#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
using namespace std;
 
int main() {
      #ifdef Icry
            auto begin = chrono :: high_resolution_clock :: now();
      #endif
      ios_base :: sync_with_stdio(0);
      cin.tie(0);
 
      int t; cin >> t;
      while (t--) {
            int n; cin >> n;
            if (n == 2) cout << "-1\n";
            else {
                  vector <vector <int>> mat(n, vector <int>(n, 0));
                  // memset(mat, 0, sizeof mat);
                  int val = 1;
                  for (int i = 0; i < n && val <= n * n; ++i) {
                        for (int j = 0; j < n && val <= n * n; ++j) {
                              mat[i][j] = val;
                              val += 2;
                        }
                  }
                  val = 2;
                  for (int i = 0; i < n && val <= n * n; ++i) {
                        for (int j = 0; j < n && val <= n * n; j++) {
                              if (mat[i][j] == 0) mat[i][j] = val, val += 2;
                        }
                  }
 
                  for (int i = 0; i < n; ++i) {
                        for (int j = 0; j < n; ++j) {
                              cout << mat[i][j] << ' ';
                        }
                        cout << '\n';
                  }
            }
      }
 
      #ifdef Icry
            auto end = chrono :: high_resolution_clock :: now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << chrono :: duration_cast <chrono :: duration <double>> (end - begin).count() << " seconds]\n";  
      #endif
}