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
            int id[2 * n + 1];
            memset(id, 0, sizeof id);
            vector <int> a(n); for (int &x : a) cin >> x;
            for (int i = 0; i < n; ++i) id[a[i]] = i + 1;
            auto getfacs = [&](int x) {
                  vector <int> facs;
                  for (int i = 1; i * i <= x; ++i) {
                        if (x % i == 0) {
                              facs.push_back(i);
                              if (x / i != i) facs.push_back(x / i);
                        }
                  }
                  return facs;
            };
 
            int ans = 0;
            for (int s = 3; s < 2 * n; ++s) {
                  auto facs = getfacs(s);
                  for (int x : facs) {
                        int i = id[x], j = id[s / x];
                        if (i == j || !i || !j) continue;
                        ans += i + j == s;
                  }
            }
 
            cout << ans / 2 << '\n';
      }
 
      #ifdef Icry
            auto end = chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << chrono::duration_cast <chrono :: duration <double>> (end - begin).count() << " seconds]\n";  
      #endif
}