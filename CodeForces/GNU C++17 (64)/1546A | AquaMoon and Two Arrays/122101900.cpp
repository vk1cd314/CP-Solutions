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
            vector <int> b(n); for (int &x : b) cin >> x;
 
            int s1 = accumulate(a.begin(), a.end(), 0);
            int s2 = accumulate(b.begin(), b.end(), 0);
            
            if (s1 != s2) {
                  cout << "-1\n";
                  continue;
            }
 
            vector <int> big, smol;
            for (int i = 0; i < n; ++i) {
                  if (a[i] < b[i]) smol.push_back(i);
                  if (a[i] > b[i]) big.push_back(i);
            }
 
            vector <pair <int, int>> ops;
            for (int i = 0; i < (int) big.size(); ++i) {
                  int need = a[big[i]] - b[big[i]];
                  for (int j = 0; j < (int) smol.size(); ++j) {
                        int have = b[smol[j]] - a[smol[j]];
                        if (need - have >= 0) {
                              need -= have;
                              for (int k = 0; k < have; ++k) {
                                    ops.push_back({big[i] + 1, smol[j] + 1});
                              }
                              a[smol[j]] = b[smol[j]];
                        } else {
                              for (int k = 0; k < need; ++k) {
                                    ops.push_back({big[i] + 1, smol[j] + 1});
                              }
                              a[smol[j]] += need;
                              need = 0;
                        }
                  }
                  assert(need == 0); 
                  a[big[i]] = b[big[i]];
            }
 
            debug(ops);
            assert(ops.size() <= 100);
            cout << ops.size() << '\n';
            for (auto [x, y] : ops) cout << x << ' ' << y << '\n';
      }
 
      #ifdef Icry
            auto end = chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << chrono::duration_cast <chrono :: duration <double>> (end - begin).count() << " seconds]\n";  
      #endif
}