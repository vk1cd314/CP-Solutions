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
            int h, w; cin >> h >> w;
            char gr[h][w];
            for (int i = 0; i < h; ++i) {
                  for (int j = 0; j < w; ++j) {
                        gr[i][j] = '0';
                  }
            }
            for (int i = 0; i < w; i += 2) {
                  gr[0][i] = '1';
            }
            if (w % 2 == 0) gr[0][w - 1] = '1', gr[0][w - 2] = '0';
            for (int i = 0; i < h; i += 2) {
                  gr[i][0] = '1';
            } 
            if (h % 2 == 0) gr[h - 1][0] = '1', gr[h - 2][0] = '0';
            for (int i = 0; i < w; i += 2) {
                  gr[h - 1][i] = '1';
            }
            if (w % 2 == 0) gr[h - 1][w - 1] = '1', gr[h - 1][w - 2] = '0';
            for (int i = 0; i < h; i += 2) {
                  gr[i][w - 1] = '1';
            } 
            if (h % 2 == 0) gr[h - 1][w - 1] = '1', gr[h - 2][w - 1] = '0';
 
            for (int i = 0; i < h; ++i) {
                  for (int j = 0; j < w; ++j) {
                        cout << gr[i][j];
                  }
                  cout << '\n';
            }
            cout << '\n';
      }
 
      #ifdef Icry
            auto end = chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << chrono::duration_cast <chrono :: duration <double>> (end - begin).count() << " seconds]\n";  
      #endif
}