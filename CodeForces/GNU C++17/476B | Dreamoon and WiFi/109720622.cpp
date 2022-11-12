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
 
      string s1, s2; cin >> s1 >> s2;
      int dest = 0;
      for (char c : s1) dest += (c == '+' ? 1 : -1);
      int have = 0, part = 0;
      for (char c : s2) have += (c == '?'), part += (c == '+' ? 1 : (c == '-' ? -1 : 69 * 0));
      
      int can = 0;
      for (int i = 0; i < (1 << have); ++i) {
            int extra = 0;
            for (int j = 0; j < have; ++j) {
                  if (i & 1 << j) ++extra;
                  else --extra;
            }
            debug(i, part, extra, dest);
            if (part + extra == dest) ++can;
      }
 
      debug(can);
      double ans = double(can) / double(1 << have);
      cout << fixed << setprecision(10) << ans << '\n';
 
      #ifdef Icry
            auto end = std::chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << std::chrono::duration_cast <std::chrono::duration <double>>(end - begin).count() << " seconds]\n";  
      #endif
}