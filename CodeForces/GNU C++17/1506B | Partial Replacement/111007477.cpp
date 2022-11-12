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
            int ct = 0;
            for (char c : s) ct += (c == '*');
 
            if (ct == 1) {
                  cout << "1\n";
                  continue;
            }
            if (ct == 2) {
                  cout << "2\n";
                  continue;
            }
            vector <int> ids;
            for (int i = 0; i < n; ++i) if (s[i] == '*') ids.push_back(i);
            int curr = 0, ans = 1, ok = 1, prev = ids[0];
            debug(ids);
            for (int i = 1; i < (int) ids.size(); ++i) {
                  curr = ids[i] - prev;
                  if (curr > k) {
                        if (i - 1 != 0) ans++;
                        curr = 0;
                        prev = ids[i - 1];
                  }
            }
            cout << ans + ok << '\n';
      }
 
      #ifdef Icry
            auto end = std::chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << std::chrono::duration_cast <std::chrono::duration <double>>(end - begin).count() << " seconds]\n";  
      #endif
}