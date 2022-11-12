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
      outer: while (t--) {
            int n; cin >> n;
            string s; cin >> s;
            if (not (s[0] == '1' and s[n - 1] == '1')) {
                  cout << "NO\n";
                  continue;
            }
            
            int cnt0 = count(s.begin(), s.end(), '0');
            int cnt1 = count(s.begin(), s.end(), '1');
            if (cnt0 % 2 or cnt1 % 2) {
                  cout << "NO\n";
                  goto outer;
            }
 
            vector <int> pos[2];
            for (int i = 0; i < n; pos[s[i] - '0'].push_back(i), ++i); 
 
            string a(n, '#'), b(n, '#');
            for (int i = 0, x; i < cnt1; 
                  x = pos[1][i], a[x] = i < cnt1 / 2 ? '(' : ')', b[x] = a[x], ++i);
            bool ded = true;
            for (int i = 0, x; i < cnt0; 
                  x = pos[0][i], a[x] = ded ^ 1 ? ')' : '(', 
                        b[x] = a[x] == '(' ? ')' : '(', ded ^= 1, ++i);
            cout << "YES\n";
            cout << a << '\n' << b << '\n';
      }
 
      #ifdef Icry
            auto end = std::chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << std::chrono::duration_cast <std::chrono::duration <double>>(end - begin).count() << " seconds]\n";  
      #endif
}