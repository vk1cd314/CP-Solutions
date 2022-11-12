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
            int mx = 0;
            if (n & 1) mx = n / 2;
            else mx = n / 2 - 1;
 
            if (k > mx) cout << "-1\n";
            else {      
                  int x = 1, y = n;
                  vector <int> ded;
                  for (int i = 0; i < n; ++i) {
                        if (i & 1) ded.push_back(y--);
                        else ded.push_back(x++);
                        int sz = ded.size();
                        int cnt = 0;
                        for (int j = 1; j + 1 < sz; ++j) {
                              if (ded[j - 1] < ded[j] && ded[j] > ded[j + 1]) ++cnt;
                        }
                        debug(ded, cnt);
                        if (cnt == k) break;
                  }
                  map <int, int> sed; 
                  for (int x : ded) sed[x]++;
 
                  for (int i = 1; i <= n; ++i) {
                        if (sed[i] == 0) ded.push_back(i);
                  }
                  debug(ded, k);
                  for (int x : ded) cout << x << ' ';
                  cout << '\n';
            }
      }
 
      #ifdef Icry
            auto end = std::chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << std::chrono::duration_cast <std::chrono::duration <double>>(end - begin).count() << " seconds]\n";  
      #endif
}