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
            int n, k; cin >> n >> k;
            multiset <int> a; for (int i = 0, x; i < n; ++i) cin >> x, a.insert(x);
            debug(a);
            set <int> ss; for (int i = 0; i <= n; ++i) ss.insert(i);
            for (auto dd : a) if (ss.count(dd)) ss.erase(dd);
 
            debug(a, ss);
            int mex = *ss.begin();
            int mx = *a.rbegin();
 
            if (mex == mx + 1) cout << n + k << '\n';
            else {
                  a.insert((mex + mx + 1) / 2);
                  set <int> fin; for (auto dd : a) fin.insert(dd);
                  cout << (!k ? n : (int) fin.size()) << '\n';
            }
      }
 
      #ifdef Icry
            auto end = std::chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << std::chrono::duration_cast <std::chrono::duration <double>>(end - begin).count() << " seconds]\n";  
      #endif
}