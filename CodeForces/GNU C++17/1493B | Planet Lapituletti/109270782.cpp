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
      // ios_base :: sync_with_stdio(0);
      // cin.tie(0);
 
      int t; cin >> t;
      while (t--) {
            int h, m; cin >> h >> m;
            string s; cin >> s;
            int h1, m1; 
            h1 = (s[0] - '0') * 10 + (s[1] - '0');
            m1 = (s[3] - '0') * 10 + (s[4] - '0');
 
            auto minDiff = [&](pair <int, int> a, pair <int, int> b) { // a always greater time
                  int d1;
                  if (a >= b) d1 = (a.first - b.first) * m + (a.second - b.second);
                  else d1 = h * m - b.first * m - b.second + a.first * m + a.second;
                  return d1;
            };
            auto correct = [&](int a, int b) {
                  vector <int> digs(2), digs1(2);
                  digs[0] = a % 10; a /= 10;
                  digs[1] = a;
                  digs1[0] = b % 10; b /= 10;
                  digs1[1] = b;
                  // debug(digs, digs1);
                  for (int &x : digs) {
                        // debug(x);
                        if (x == 0) continue;
                        if (x == 1) continue;
                        if (x == 2) {
                              x = 5;
                              continue;
                        }
                        if (x == 5) {
                              x = 2;
                              continue;
                        }
                        if (x == 8) continue;
                        return make_pair(-1, -1);
                  }
                  for (int &x : digs1) {
                        // debug(x);
                        if (x == 0) continue;
                        if (x == 1) continue;
                        if (x == 2) {
                              x = 5;
                              continue;
                        }
                        if (x == 5) {
                              x = 2;
                              continue;
                        }
                        if (x == 8) continue;
                        return make_pair(-1, -1);
                  }
                  if (digs[0] * 10 + digs[1] < m && digs1[0] * 10 + digs1[1] < h) return make_pair(digs1[0] * 10 + digs1[1], digs[0] * 10 + digs[1]);
                  return make_pair(-1, -1);
            };
 
            int ans = INT_MAX;
            pair <int, int> magi = {-1, -1};
            vector <int> khanki = {0, 1, 2, 5, 8};
            for (int i = 0; i < 5; ++i) {
                  for (int j = 0; j < 5; ++j) {
                        for (int k = 0; k < 5; ++k) {
                              for (int l = 0; l < 5; ++l) {
                                    int h2 = khanki[i] * 10 + khanki[j];
                                    int m2 = khanki[k] * 10 + khanki[l];
                                    pair <int, int> pp = correct(h2, m2);
                                    if (pp == make_pair(-1, -1)) continue;
                                    if (correct(pp.first, pp.second) == make_pair(-1, -1)) continue;
                                    // debug(h2, m2);
                                    pair <int, int> pp1 = {h1, m1};
                                    int mi = minDiff(pp, pp1);
                                    if (h2 == 0 && m2 == 0) {
                                          debug(mi);
                                    }
                                    if (mi < ans) {
                                          // debug(pp, h2, m2);
                                          ans = mi;
                                          magi = pp;
                                    }
                              }
                        }
                  }
            }
            debug(ans);
            if (magi.first > 9) cout << magi.first;
            else cout << "0" << magi.first;
            cout << ":";
            if (magi.second > 9) cout << magi.second;
            else cout << "0" << magi.second;
            cout << '\n';
      }
 
      #ifdef Icry
            auto end = std::chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << std::chrono::duration_cast <std::chrono::duration <double>>(end - begin).count() << " seconds]\n";  
      #endif
}