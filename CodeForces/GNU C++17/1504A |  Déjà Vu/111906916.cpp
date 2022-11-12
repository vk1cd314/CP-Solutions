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
            string s, a, b;
            cin >> s;
            bool ok = false;
            int len = s.size() + 1;
            a = 'a' + s;
            b = s + 'a';
            for (int i = 0; i < len / 2; ++i) {
                  if (a[i] != a[len - 1 - i]) {
                        ok = true;
                        cout << "YES\n";
                        cout << a << '\n';
                        break;
                  }
            }
            if (!ok) {
                  for(int i = 0; i < len / 2; ++i) {
                        if (b[i] != b[len - 1 - i]) {
                              ok = true;
                              cout << "YES\n";
                              cout << b << '\n';
                              break;
                        }
                  }
            }
            if (!ok) cout<<"NO\n";
      }
 
      #ifdef Icry
            auto end = std::chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << std::chrono::duration_cast <std::chrono::duration <double>>(end - begin).count() << " seconds]\n";  
      #endif
}