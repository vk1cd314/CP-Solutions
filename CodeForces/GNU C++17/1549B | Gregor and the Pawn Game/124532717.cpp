#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
using namespace std;
 
int main() {
      #ifdef Icry
            auto begin = chrono::high_resolution_clock::now();
      #endif
      ios_base::sync_with_stdio(0);
      cin.tie(0);
 
      int t; cin >> t;
      while (t--) {
            int n; cin >> n;
            string s[2]; cin >> s[0] >> s[1];
            int ans = 0;
            int taken[n];
            memset(taken, 0, sizeof taken);
            for (int i = 0; i < n; ++i) {
                  if (s[1][i] == '1' && s[0][i] == '0') ++ans, taken[i]++;
                  else if (s[1][i] == '1') {
                        if (i - 1 >= 0 && !taken[i - 1] && s[0][i - 1] == '1') ++ans, taken[i - 1]++;
                        else if (i + 1 < n && !taken[i + 1] && s[0][i + 1] == '1') ++ans, taken[i + 1]++; 
                  }
            }
 
            cout << ans << '\n';
      }
 
      #ifdef Icry
            auto end = chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << chrono::duration_cast <chrono :: duration <double>> (end - begin).count() << " seconds]\n";  
      #endif
}