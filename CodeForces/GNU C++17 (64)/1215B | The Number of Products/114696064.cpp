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
 
      int n; cin >> n;
      vector <int64_t> a(n); for (auto &x : a) cin >> x;
 
      int64_t curr = 0, cntpos = 0, cntneg = 0;
      for (int i = 0; i < n; ++i) {
            curr += a[i] < 0;
            if (curr & 1) cntneg++;
            else cntpos++;
      }
 
      int64_t numpos = (cntpos * (cntpos - 1)) / 2 + (cntneg * (cntneg - 1)) / 2;
      int64_t numneg = (cntpos * cntneg);
 
      cout << numneg + cntneg << ' ' << numpos + cntpos << '\n';
 
      #ifdef Icry
            auto end = std::chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << std::chrono::duration_cast <std::chrono::duration <double>>(end - begin).count() << " seconds]\n";  
      #endif
}