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
            string s; cin >> s;
            bool ok1 = true, ok2 = true, ok3 = false;
            for (int i = 1; i < (int) s.size(); ++i) {
                  if (s[i] == '0' && s[i - 1] == s[i]) ok1 = false;
                  if (s[i] == '1' && s[i - 1] == s[i]) ok2 = false;
            }
 
            if (ok1 || ok2) {
                  cout << "YES\n";
                  continue;
            }
 
            for (int i = 1; i < (int) s.size(); ++i) {
                  bool ys1 = true, ys2 = true;
                  for (int j = 1; j < i; ++j) {
                        if (s[j] == '1' && s[j - 1] == s[j]) ys1 = false;
                  }
                  for (int j = i; j < (int) s.size(); ++j) {
                        if (s[j] == '0' && s[j - 1] == s[j]) ys2 = false;
                  }
                  if (ys1 && ys2) {
                        ok3 = true;
                        break;
                  }
            }
            if (ok3) cout << "YES\n";
            else cout << "NO\n";
      }
 
      #ifdef Icry
            auto end = std::chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << std::chrono::duration_cast <std::chrono::duration <double>>(end - begin).count() << " seconds]\n";  
      #endif
}