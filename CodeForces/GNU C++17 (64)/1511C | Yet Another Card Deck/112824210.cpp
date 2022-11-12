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
 
      int n, q; cin >> n >> q;
      vector <int> a(n); for (int &x : a) cin >> x;
      vector <int> t(q); for (int &x : t) cin >> x;
 
      map <int, int> cnt;
 
      vector <int> out(q);
      for (int i = 0; i < n; ++i) if (!cnt[a[i]]) cnt[a[i]] = i + 1;
      for (int i = 0; i < q; ++i) {
            out[i] = cnt[t[i]];
            for (auto [x, y] : cnt) {
                  if (y < cnt[t[i]]) cnt[x]++;
            }
            cnt[t[i]] = 1;
      }
      
      for (int x : out) cout << x << ' ';
 
      #ifdef Icry
            auto end = std::chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << std::chrono::duration_cast <std::chrono::duration <double>>(end - begin).count() << " seconds]\n";  
      #endif
}