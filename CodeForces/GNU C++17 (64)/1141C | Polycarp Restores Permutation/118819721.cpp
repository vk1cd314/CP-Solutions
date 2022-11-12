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
 
      int64_t n; cin >> n;
      vector <int64_t> q(n - 1); for (auto &x : q) cin >> x;
 
      for (int i = 1; i < n - 1; ++i) q[i] += q[i - 1];
      int64_t sum = accumulate(q.begin(), q.end(), 0LL);
 
      int64_t p1 = ((n * (n + 1)) / 2 - sum) / n;
      if (p1 <= 0) {
            cout << -1 << '\n';
            return 0;
      }
      set <int> ss;
      for (auto x : q) {
            if (x + p1 <= 0) {
                  cout << -1 << '\n';
                  return 0;
            }
            ss.insert(x + p1);
      }
      ss.insert(p1);
      debug(ss);
      debug(q);
      debug(p1);
      if ((int) ss.size() != n) {
            cout << -1 << '\n';
            return 0;
      }
 
      cout << p1 << ' ';
      for (auto x : q) cout << x + p1 << ' ';
      cout << '\n';
 
      #ifdef Icry
            auto end = chrono :: high_resolution_clock :: now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << chrono :: duration_cast <chrono :: duration <double>> (end - begin).count() << " seconds]\n";  
      #endif
}