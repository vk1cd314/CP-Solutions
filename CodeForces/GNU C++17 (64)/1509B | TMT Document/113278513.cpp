#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
using namespace std;
 
int main() {
      #ifdef Icry
            auto begin = chrono :: high_resolution_clock :: now();
      #endif
      ios_base :: sync_with_stdio(0);
      cin.tie(0);
 
      int t; cin >> t;
      while (t--) {
            int n; cin >> n;
            string s; cin >> s;
            vector <int> preT(n, 0), preM(n, 0), suffT(n, 0), suffM(n, 0);
            preT[0] = s[0] == 'T', preM[0] = s[0] == 'M';
            for (int i = 1; i < n; ++i) preT[i] = preT[i - 1] + (s[i] == 'T'), preM[i] = preM[i - 1] + (s[i] == 'M');
            suffT[n - 1] = s.back() == 'T', suffM[n - 1] = s.back() == 'M';
            for (int i = n - 2; i >= 0; --i) suffT[i] = suffT[i + 1] + (s[i] == 'T'), suffM[i] = suffM[i + 1] + (s[i] == 'M');
 
            bool ok = true;
            for (int i = 0; i < n; ++i) ok &= preT[i] >= preM[i];
            for (int i = n - 1; i >= 0; --i) ok &= suffT[i] >= suffM[i];
 
            if (ok && preT.back() == preM.back() * 2) cout << "YES\n";
            else cout << "NO\n";
      }
 
      #ifdef Icry
            auto end = chrono :: high_resolution_clock :: now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << chrono :: duration_cast <chrono :: duration <double>> (end - begin).count() << " seconds]\n";  
      #endif
}