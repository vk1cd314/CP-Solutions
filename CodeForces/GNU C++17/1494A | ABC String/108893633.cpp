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
            string a; cin >> a;
 
            auto check = [&](string dd) {
                  int c0 = 0;
                  bool ok = true;
                  for (char c : dd) {
                        if (c == '(') ++c0;
                        if (c == ')') --c0;
                        if (c0 < 0) ok = false;
                  }
                  if (c0 != 0) ok = false;
                  return ok;
            };
            debug(check("(())(((())))()"));
 
            bool ok = false;
            string ff = "()";
            for (int i = 0; i < 2; ++i) {
                  for (int j = 0; j < 2; ++j) {
                        for (int k = 0; k < 2; ++k) {
                              string b = a;
                              for (char &c : b) {
                                    if (c == 'A') c = ff[i];
                                    if (c == 'B') c = ff[j];
                                    if (c == 'C') c = ff[k];
                              }
                              if (check(b)) ok = true;
                              if (ok) break;
                        }
                        if (ok) break;
                  }
                  if (ok) break;
            }
 
            if (ok) cout << "YES\n";
            else cout << "NO\n";
            
      }
 
      #ifdef Icry
            auto end = std::chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << std::chrono::duration_cast <std::chrono::duration <double>>(end - begin).count() << " seconds]\n";  
      #endif
}