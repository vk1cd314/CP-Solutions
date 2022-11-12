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
            char aa[n][m];
            set <char> bb[2];
            for (int i = 0; i < n; ++i) {
                  for (int j = 0; j < m; ++j) {
                        cin >> aa[i][j];
                        if (aa[i][j] != '.') {
                              bb[(i + j) % 2].insert(aa[i][j]);
                        }
                  }
            }
 
            if (bb[0].empty() && bb[1].empty()) {
                  cout << "YES\n";
                  for (int i = 0; i < n; ++i) {
                        for (int j = 0; j < m; ++j) {
                              cout << ((i + j) % 2 ? "R" : "W");
                        }
                        cout << '\n';
                  }
            } else if (bb[0].size() == 1 && bb[1].size() == 1) {
                  cout << (*bb[0].begin() != *bb[1].begin() ? "YES\n" : "NO\n");
                  if (*bb[0].begin() != *bb[1].begin()) {
                        for (int i = 0; i < n; ++i) {
                              for (int j = 0; j < m; ++j) {
                                    if (aa[i][j] == '.') cout << *bb[(i + j) % 2].begin();
                                    else cout << aa[i][j];
                              }
                              cout << '\n';
                        }
                  }
            } else if (bb[0].size() == 1 && bb[1].empty()) {
                  cout << "YES\n";
                  char oppo = *bb[0].begin() == 'W' ? 'R' : 'W';
                  for (int i = 0; i < n; ++i) {
                        for (int j = 0; j < m; ++j) {
                              if (aa[i][j] == '.') {
                                    if ((i + j) % 2 == 0) cout << *bb[(i + j) % 2].begin();
                                    else cout << oppo;
                              } else cout << aa[i][j];
                        }
                        cout << '\n';
                  }
            } else if (bb[1].size() == 1 && bb[0].empty()) {
                  cout << "YES\n";
                  char oppo = *bb[1].begin() == 'W' ? 'R' : 'W';
                  for (int i = 0; i < n; ++i) {
                        for (int j = 0; j < m; ++j) {
                              if (aa[i][j] == '.') {
                                    if ((i + j) % 2 == 1) cout << *bb[(i + j) % 2].begin();
                                    else cout << oppo;
                              } else cout << aa[i][j];
                        }
                        cout << '\n';
                  }
            } else {
                  cout << "NO\n";
            }
      }
 
      #ifdef Icry
            auto end = chrono :: high_resolution_clock :: now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << chrono :: duration_cast <chrono :: duration <double>> (end - begin).count() << " seconds]\n";  
      #endif
}