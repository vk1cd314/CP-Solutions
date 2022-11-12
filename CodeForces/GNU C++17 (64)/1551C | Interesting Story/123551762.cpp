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
            vector <string> a(n); for (auto &s : a) cin >> s;
            int ans = 0;
            // debug(a);
            for (char c = 'a'; c <= 'e'; ++c) {
                  vector <int> cnt(n);
                  for (int i = 0; i < n; ++i) {
                        int ct = count(a[i].begin(), a[i].end(), c);
                        int diff = a[i].size() - ct;
                        cnt[i] = ct - diff;                        
                  }
                  sort(cnt.rbegin(), cnt.rend());
                  // debug(cnt);  
                  int pre = 0;   
                  bool ded = true;
                  for (int i = 0; i < (int)cnt.size(); ++i) {
                        pre += cnt[i];
                        if (pre <= 0) {
                              ans = max(ans, i); 
                              ded ^= 1;
                              break;
                        }
                  }
                  if (ded) ans = max(ans, n);
            }
 
            cout << ans << '\n';
      }
 
      #ifdef Icry
            auto end = chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << chrono::duration_cast <chrono :: duration <double>> (end - begin).count() << " seconds]\n";  
      #endif
}