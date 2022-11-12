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
            int n, m; cin >> n >> m;
            vector <string> a(n); for (auto &x : a) cin >> x;
 
            int cnt[m][30], cnt1[m][30];
            for (int i = 0; i < m; ++i) {
                  memset(cnt[i], 0, sizeof cnt[i]);
                  memset(cnt1[i], 0, sizeof cnt1[i]);
            }
            
            for (auto s : a) {
                  for (int i = 0; i < m; ++i) {
                        cnt[i][s[i] - 'a']++;
                  }
            }
            vector <string> aa(n - 1); for (auto &x : aa) cin >> x;
 
            for (auto s : aa) {
                  for (int i = 0; i < m; ++i) {
                        cnt1[i][s[i] - 'a']++;
                  }
            }
 
            string ss(m, '#');
            // debug(ss);
            for (int i = 0; i < m; ++i) {
                  for (int j = 0; j < 26; ++j) {
                        if (cnt[i][j] != cnt1[i][j]) {
                              ss[i] = char('a' + j);
                              break;
                        }
                  }
            }
 
            debug(ss);
            cout << ss << endl;
      }
 
      #ifdef Icry
            auto end = chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << chrono::duration_cast <chrono :: duration <double>> (end - begin).count() << " seconds]\n";  
      #endif
}