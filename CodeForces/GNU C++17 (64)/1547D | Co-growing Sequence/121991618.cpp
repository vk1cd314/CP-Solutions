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
            vector <int64_t> a(n); for (auto &x : a) cin >> x;
            vector <int64_t> ans(n, 0);
            for (int i = 0; i + 1 < n; ++i) {
                  int64_t need = 0;
                  for (int64_t j = 0; j < 31; ++j) {
                        if ((a[i] & (1 << j)) && !(a[i + 1] & (1 << j))) need += 1LL << j;
                  }
                  a[i + 1] += need;
                  ans[i + 1] = need;
            }
            for (int x : ans) cout << x << ' ';
            cout << '\n';
      }
 
      #ifdef Icry
            auto end = chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << chrono::duration_cast <chrono :: duration <double>> (end - begin).count() << " seconds]\n";  
      #endif
}