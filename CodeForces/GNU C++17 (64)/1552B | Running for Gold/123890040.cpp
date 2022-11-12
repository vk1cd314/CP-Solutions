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
            int n; cin >> n;
            int r[n][5];
            for (int i = 0; i < n; ++i) {
                  for (int j = 0; j < 5; ++j) {
                        cin >> r[i][j];
                  }
            } 
            auto points = [&](int i, int j) {
                  int ct = 0;
                  for (int x = 0; x < 5; ++x) {
                        ct += r[i][x] < r[j][x];
                  }
                  return ct;
            };
 
            int bestid = 0;
            for (int i = 0; i < n; ++i) {
                  if (points(bestid, i) < 3) bestid = i;
                  // debug(points(bestid, i));
                  // debug(bestid, i);
            }
 
            bool hobe = true;
            for (int i = 0; i < n; ++i) {
                  if (i != bestid && points(bestid, i) < 3) {
                        // debug(points(bestid, i));
                        // debug(bestid, i);
                        hobe = false;
                        break;
                  }
            }
 
            cout << (hobe ? bestid + 1 : -1) << '\n';
      }
 
      #ifdef Icry
            auto end = chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << chrono::duration_cast <chrono :: duration <double>> (end - begin).count() << " seconds]\n";  
      #endif
}