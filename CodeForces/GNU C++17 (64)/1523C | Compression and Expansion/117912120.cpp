#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...)
#endif
 
using namespace std;
 
int main() {
#ifdef Icry
      auto begin = chrono ::high_resolution_clock ::now();
#endif
      ios_base ::sync_with_stdio(0);
      cin.tie(0);
 
      int t;
      cin >> t;
      while (t--) {
            int n;
            cin >> n;
            vector<int> a(n);
            for (int &x : a) cin >> x;
 
            deque <int> have;
            for (int i = 0; i < n; ++i) {
                  if (a[i] == 1) {
                        have.push_back(1);
                        for (int j = 0; j < (int) have.size(); ++j) {
                              if (j) cout << ".";
                              cout << have[j];
                        }
                        cout << '\n';
                  } else {
                        if (!have.empty() && a[i] == have.back() + 1) {
                              have.back()++;
                              for (int j = 0; j < (int) have.size(); ++j) {
                                    if (j) cout << ".";
                                    cout << have[j];
                              }
                              cout << '\n';
                        } else {
                              while (!have.empty() && have.back() + 1 != a[i]) have.pop_back();
                              if (!have.empty()) have.pop_back();
                              have.push_back(a[i]);
                              for (int j = 0; j < (int) have.size(); ++j) {
                                    if (j) cout << ".";
                                    cout << have[j];
                              }
                              cout << '\n';
                        }
                  }
            }
      }
 
#ifdef Icry
      auto end = chrono ::high_resolution_clock ::now();
      cerr << setprecision(4) << fixed;
      cerr << "[Execution time: " << chrono ::duration_cast<chrono ::duration<double>>(end - begin).count() << " seconds]\n";
#endif
}