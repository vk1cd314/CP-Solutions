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
 
      int t; cin >> t;
      here: while (t--) {
            int n; cin >> n;
            vector <int64_t> a(n); for (auto &x : a) cin >> x;
 
            int muh = 0;
            for (int i = 0; i < n - 1; ++i) {
                  int dud = 0;
                  bool haha = false;
                  muh ^= a[i];
                  for(int j = i + 1; j < n; ++j) {
                        dud ^= a[j];
                        if(muh == dud) {
                              haha = true;
                              dud = 0;
                        }
                  }
                  if(muh == dud || (haha && !dud)) {
                        cout << "YES\n";
                        goto here;
                  }
            } 
            cout << "NO\n";
      }
 
      #ifdef Icry
            auto end = chrono :: high_resolution_clock :: now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << chrono :: duration_cast <chrono :: duration <double>> (end - begin).count() << " seconds]\n";  
      #endif
}