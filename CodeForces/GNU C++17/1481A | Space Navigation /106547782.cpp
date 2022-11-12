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
            int x, y; cin >> x >> y;
            int cu = 0, cd = 0, cr = 0, cl = 0;
            string s; cin >> s;
            for (int i = 0;i < s.size(); ++i) {
                  if (s[i] == 'U') cu++;
                  else if (s[i] == 'D') cd--;
                  else if (s[i] == 'R') cr++;
                  else if (s[i] == 'L') cl--;
            }
 
            if((x <= cr && x >= cl) && (y <= cu && y >= cd)) cout<< "YES\n";
            else cout<< "NO\n";
      }
 
      #ifdef SENDHELP
            auto end = std::chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << std::chrono::duration_cast <std::chrono::duration <double>>(end - begin).count() << " seconds]\n";  
      #endif
}