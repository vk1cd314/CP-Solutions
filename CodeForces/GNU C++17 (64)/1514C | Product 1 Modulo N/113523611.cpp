#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
using namespace std;
 
int64_t n;
vector <int> curr;
vector <int> acc;
void rec(int i) {
      if (i == n) {
            int res = 1;
            for (int x : curr) res = (res * x) % n;
            if (res == 1) {
                  // debug(curr);
                  if (curr.size() > acc.size()) acc = curr;
            }
            return;
      }
      curr.push_back(i);
      rec(i + 1);
      curr.pop_back();
      rec(i + 1);
}
 
int main() {
      #ifdef Icry
            auto begin = chrono :: high_resolution_clock :: now();
      #endif
      ios_base :: sync_with_stdio(0);
      cin.tie(0);
 
 
      cin >> n;
      // rec(1);
 
      int tmp = n;
      set <int64_t> facs;
      for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) {
                  facs.insert(i);
                  facs.insert(n / i);
            }
      }
 
      debug(facs);
      vector <int> ans;
      for (int i = 1; i < tmp; ++i) {
            bool ok = true;
            for (auto x : facs) {
                  if (i % x == 0) {
                        debug(i, x);
                        ok = false;
                        break;
                  }
            }
            // debug(i);
            if (ok) {
                  // debug("what");
                  ans.push_back(i);
            }
      }
 
      debug(ans);
      int64_t res = 1;
      for (auto x : ans) res = (res * x) % tmp;
 
      if (res != 1) ans.pop_back();
 
      // debug(acc);
      // assert(ans == acc);
      cout << ans.size() << '\n';
      for (auto x : ans) cout << x << ' ';
 
      #ifdef Icry
            auto end = chrono :: high_resolution_clock :: now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << chrono :: duration_cast <chrono :: duration <double>> (end - begin).count() << " seconds]\n";  
      #endif
}