#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
using namespace std;
 
int main() {
      #ifdef Icry
            auto begin = std::chrono::high_resolution_clock::now();
      #endif
      ios_base :: sync_with_stdio(0);
      cin.tie(0);
 
      int t; cin >> t;
      while (t--) {
            int n; cin >> n;
            vector <int> a(n); for (int& x : a) cin >> x;
            map <int, int> cnt;
            for (int x : a) cnt[x]++;
            bool ok = true;
            while (3) {
                  if (!ok) break;
                  bool ded = false;
                  for (int i = 0; i <= 101; ++i) {
                        if (cnt[i]) {
                              ded = true;
                              cout << i << ' ';
                              cnt[i]--;
                        }
                  }
                  ok = ded;
            }
            cout << '\n';
      }
 
      #ifdef Icry
            auto end = std::chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << std::chrono::duration_cast <std::chrono::duration <double>>(end - begin).count() << " seconds]\n";  
      #endif
}