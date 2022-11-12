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
            int n; cin >> n;
            string s; cin >> s;
            if (!(s[0] == '1' && s[n - 1] == '1')) {
                  cout << "NO\n";
                  continue;
            }
            
            int cnt0 = count(s.begin(), s.end(), '0');
            int cnt1 = count(s.begin(), s.end(), '1');
            if (cnt0 % 2 or cnt1 % 2) {
                  cout << "NO\n";
                  continue;
            }
 
            vector <int> pos[2];
            for (int i = 0; i < n; ++i) pos[s[i] - '0'].push_back(i);
 
            string a(n, '#'), b(n, '#');
            assert((int) pos[1].size() == cnt1 && (int) pos[0].size() == cnt0);
            debug(pos[0], pos[1]);
            for (int i = 0; i < (int) pos[1].size(); ++i) a[pos[1][i]] = i < (int) pos[1].size() / 2 ? '(' : ')', b[pos[1][i]] = a[pos[1][i]];
            bool ded = true;
            for (int i = 0; i < (int) pos[0].size(); ++i) a[pos[0][i]] = ded ^ 1 ? ')' : '(', b[pos[0][i]] = a[pos[0][i]] == '(' ? ')' : '(', ded ^= 1;
            
            cout << "YES\n";
            cout << a << '\n' << b << '\n';
      }
 
      #ifdef Icry
            auto end = std::chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << std::chrono::duration_cast <std::chrono::duration <double>>(end - begin).count() << " seconds]\n";  
      #endif
}