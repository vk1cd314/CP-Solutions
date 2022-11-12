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
            vector <int> a(n); for (int &x : a) cin >> x;
            map <int, set <int>> ss;
            for (int i = 0; i < n; ++i) {
                  ss[a[i]].insert(i + 1);
            }
            int k = 0;
            set <int> emp;
            for (int i = 1; i <= n; ++i) {
                  k += ss[i].size() > 0;
                  if (!ss[i].size()) emp.insert(i);
            }     
            vector <int> b(n);
            b = a;
            debug(emp);
            for (auto [x, s] : ss) {
                  if (!emp.size()) break;
                  if (s.size() > 1) {
                        int cng = 0;
                        for (int x : s) {
                              if (emp.empty()) break;
                              auto it = emp.lower_bound(x);
                              if (it == emp.end()) {
                                    b[x - 1] = *emp.begin();
                                    debug(x, *emp.begin());
                                    emp.erase(emp.begin());
                                    ++cng;
                              } else if (*it != x) {
                                    b[x - 1] = *it;
                                    debug(x, *it);
                                    emp.erase(it);
                                    ++cng;
                              } else {
                                    if ((int)emp.size() == 1) continue;
                                    else {
                                          if (it == emp.begin()) it++;
                                          else --it;
                                          b[x - 1] = *it;
                                          debug(x, *it);
                                          emp.erase(it);
                                          ++cng;
                                    }
                              }
                              if (s.size() - cng == 1) break;
                        }
                  }
            }
            debug(emp);
            debug(b);
            cout << k << '\n';
            for (int x : b) cout << x << ' ';
            cout << '\n';
      }
 
      #ifdef Icry
            auto end = chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << chrono::duration_cast <chrono :: duration <double>> (end - begin).count() << " seconds]\n";  
      #endif
}