#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
using namespace std;
 
int main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
 
      int t; cin >> t;
      while (t--) {
            int n, k; cin >> n >> k;
            auto brute = [&]() {
                  vector <int> nk(n * k);
                  iota(nk.begin(), nk.end(), 1);
                  do {
                        vector <vector <int>> aa(n, vector <int>(k));
                        int id = 0;
                        for (int i = 0; i < n; ++i) {
                              for (int j = 0; j < k; ++j) {
                                    aa[i][j] = nk[id++];
                              }
                        }
                        bool ok = true;
                        for (int i = 0; i < n; ++i) {
                              for (int l = 0; l < k; ++l) {
                                    for (int r = l; r < k; ++r) {
                                          int sum = 0;
                                          for (int k = l; k <= r; ++k) sum += aa[i][k];
                                          if (sum % (r - l + 1)) ok = false;
                                    }
                              }
                        }
                        if (ok) {
                              for (auto v : aa) {
                                    debug(v);
                              }
                              debug("done");
                              break;
                        }
                  } while (next_permutation(nk.begin(), nk.end()));
            };
            // brute();
            // guess n % 2 == 1 nope unless k = 1
            if (k == 1) {
                  cout << "YES\n";
                  vector <int> nk(n * k);
                  iota(nk.begin(), nk.end(), 1);
                  int id = 0;
                  for (int i = 0; i < n; ++i) {
                        for (int j = 0; j < k; ++j) {
                              cout << nk[id++] << ' ';
                        }
                        cout << '\n';
                  }
            } else {
                  if (n % 2 == 1) {
                        cout << "NO\n";
                  } else {
                        vector <vector <int>> aa(n, vector <int>(k));
                        int ev = 2, od = 1;
                        for (int i = 0; i < n; ++i) {
                              if (i & 1) {
                                    for (int j = 0; j < k; ++j) {
                                          aa[i][j] = ev;
                                          ev += 2;
                                    }
                              } else {
                                    for (int j = 0; j < k; ++j) {
                                          aa[i][j] = od;
                                          od += 2;
                                    }
                              }
                        }
                        cout << "YES\n";
                        for (int i = 0; i < n; ++i) {
                              for (int j = 0; j < k; ++j) {
                                    cout << aa[i][j] << ' ';
                              }
                              cout << '\n';
                        }
                  }
            }
      }
}