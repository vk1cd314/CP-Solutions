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
            int n, m; cin >> n >> m;
            string s; cin >> s;
            string ss(n, '0');
            if (s == ss) {
                  cout << s << '\n';
                  continue;
            } 
            vector <pair <char, int>> aa;
            aa.push_back({s[0], 1});
            for (int i = 1; i < n; ++i) {
                  if (aa.back().first == s[i]) aa.back().second++;
                  else {
                        aa.push_back({s[i], 1});
                  }
            }
 
            int mx = 0;
            for (int i = 0; i < (int) aa.size(); ++i) {
                  if (aa[i].first == '0') mx = max(mx, aa[i].second);
            }
 
            // if (mx == 1) {
            //       // cout << s << '\n';
            //       continue;
            // }
 
            if (mx / 2 <= m) {
                  for (int i = 0; i < (int) aa.size(); ++i) {
                        if (aa[i].first == '1') {
                              for (int j = 0; j < aa[i].second; ++j) cout << '1';
                        } else {
                              if (i == 0) {
                                    if (aa[i].second == 1) cout << '1';
                                    else {
                                          for (int j = 0; j < max(0, aa[i].second - m); ++j) {
                                                cout << '0';
                                          }
                                          for (int j = 0; j < min(aa[i].second, m); ++j) {
                                                cout << '1';
                                          }
                                    }
                              }
                              else if (i == (int) aa.size() - 1) {
                                    if (aa[i].second == 1) cout << '1';
                                    else {
                                          for (int j = 0; j < min(aa[i].second, m); ++j) {
                                                cout << '1';
                                          }
                                          for (int j = 0; j < max(0, aa[i].second - m); ++j) {
                                                cout << '0';
                                          }
                                    }
                              }
                              else {
                                    for (int j = 0; j < aa[i].second / 2; ++j) cout << '1';
                                    if (aa[i].second % 2) {
                                          cout << '0';
                                    }
                                    for (int j = 0; j < aa[i].second / 2; ++j) cout << '1';
                              }
                        }
                  }
                  // debug(33);
            } else {
                  for (int i = 0; i < (int) aa.size(); ++i) {
                        if (aa[i].first == '1') {
                              for (int j = 0; j < aa[i].second; ++j) cout << '1';
                        } else {
                              if (i == 0) {
                                    if (aa[i].second == 1) cout << '1';
                                    else {
                                          for (int j = 0; j < max(0, aa[i].second - m); ++j) {
                                                cout << '0';
                                          }
                                          for (int j = 0; j < min(aa[i].second, m); ++j) {
                                                cout << '1';
                                          }
                                    }
                              }
                              else if (i == (int) aa.size() - 1) {
                                    if (aa[i].second == 1) cout << '1';
                                    else {
                                          for (int j = 0; j < min(aa[i].second, m); ++j) {
                                                cout << '1';
                                          }
                                          for (int j = 0; j < max(0, aa[i].second - m); ++j) {
                                                cout << '0';
                                          }
                                    }
                              }
                              else if (aa[i].second == 1) {
                                    cout << '0';
                              }
                              else if (aa[i].second / 2 <= m) {
                                    for (int j = 0; j < aa[i].second / 2; ++j) cout << '1';
                                    if (aa[i].second % 2) cout << '0';
                                    for (int j = 0; j < aa[i].second / 2; ++j) cout << '1';
                              } else {
                                    for (int j = 0; j < m; ++j) cout << '1';
                                    for (int j = 0; j < aa[i].second - 2 * m; ++j) cout << '0';
                                    for (int j = 0; j < m; ++j) cout << '1';
                              }
                        }
                  } 
            }
            cout << '\n';
      }
 
      #ifdef Icry
            auto end = chrono :: high_resolution_clock :: now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << chrono :: duration_cast <chrono :: duration <double>> (end - begin).count() << " seconds]\n";  
      #endif
}