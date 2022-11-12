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
            string s; cin >> s;
            list <char> ss;
            for (char c : s) ss.push_back(c);
            int ct = 0;
            while (ss.size() > 1 && ss.back() == ss.front()) ss.pop_back(), ss.pop_front(), ++ct;
 
            if (2 * ct == n) {
                  if (ct - 1 >= k) cout << "YES\n";
                  else cout << "NO\n";
            } else {
                  if (ct >= k) cout << "YES\n";
                  else cout << "NO\n";
            }
      }
 
      #ifdef Icry
            auto end = std::chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << std::chrono::duration_cast <std::chrono::duration <double>>(end - begin).count() << " seconds]\n";  
      #endif
}