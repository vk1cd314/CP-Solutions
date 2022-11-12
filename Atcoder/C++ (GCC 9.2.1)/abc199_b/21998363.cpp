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

      int n; cin >> n;
      vector <int> a(n); for (int &x : a) cin >> x;
      vector <int> b(n); for (int &x : b) cin >> x;
      
      int cnt = 0;
      for (int i = 0; i < 1010; ++i) {
            int ded = i;
            bool ok = true;
            for (int j = 0; j < n; ++j) ok &= (a[j] <= ded && ded <= b[j]);
            cnt += ok; 
      }

      cout << cnt << '\n';

      #ifdef Icry
            auto end = chrono :: high_resolution_clock :: now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << chrono :: duration_cast <chrono :: duration <double>> (end - begin).count() << " seconds]\n";  
      #endif
}