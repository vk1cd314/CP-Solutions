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
            string a, b; cin >> a >> b;
            vector <int> pre1(n), pre2(n);
            pre1[0] = a[0] == '0' ? 1 : -1;
            pre2[0] = b[0] == '0' ? 1 : -1;
            int lst = -1;
            for (int i = 1; i < n; ++i) {
                  pre1[i] = pre1[i - 1] + (a[i] == '0' ? 1 : -1);
                  pre2[i] = pre2[i - 1] + (b[i] == '0' ? 1 : -1);
                  if (pre1[i] == 0) lst = i;
            }
 
            if (lst == -1) {
                  if (a == b) cout << "YES\n";
                  else cout << "NO\n";
                  continue;
            }
 
            bool ok = true;
            for (int i = lst + 1; i < n; ++i) ok &= (pre1[i] == pre2[i]);
 
            if (!ok) {
                  cout << "NO\n";
                  continue;
            }
 
            debug(pre1, pre2);
            ok = true;
            for (int i = 0; i < n; ++i) ok &= (abs(pre1[i]) == abs(pre2[i]));
            
            cout << (ok ? "YES\n" : "NO\n");
      }
 
      #ifdef Icry
            auto end = std::chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << std::chrono::duration_cast <std::chrono::duration <double>>(end - begin).count() << " seconds]\n";  
      #endif
}