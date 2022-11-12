#include <bits/stdc++.h>
 
using namespace std;
 
#ifdef SENDHELP
#include "debug.h"
#else
#define debug(args...)
#endif
 
int main() {
      #ifdef SENDHELP
            auto begin = std::chrono::high_resolution_clock::now();
      #endif
      ios_base :: sync_with_stdio(0);
      cin.tie(0);
 
      int t; cin >> t;
      while (t--) {
            int n; cin >> n;
            vector <int> a(n); for (int& x : a) cin >> x;
            vector <int> out(n, 0);
            
            function <void(int, int, int)> build = [&](int l, int r, int d) {
                  if (l >= r) return;
                  auto it = max_element(a.begin() + l, a.begin() + r);
                  int id = it - a.begin();
                  out[id] = d;
                  build(l, id, d + 1);
                  build(id + 1, r, d + 1);
            };
 
            build(0, n, 0);
            for (int x : out) cout << x << ' ';
            cout << '\n';
      }
 
      #ifdef SENDHELP
            auto end = std::chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << std::chrono::duration_cast <std::chrono::duration <double>>(end - begin).count() << " seconds]\n";  
      #endif
}