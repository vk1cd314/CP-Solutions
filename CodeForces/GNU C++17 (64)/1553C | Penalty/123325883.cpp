#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
using namespace std;
 
string s;
 
int main() {
      #ifdef Icry
            auto begin = chrono::high_resolution_clock::now();
      #endif
      ios_base::sync_with_stdio(0);
      cin.tie(0);
 
      int t; cin >> t;
      while (t--) {
            string s; cin >> s;
            vector <int> q;
            int n = s.size();
            for (int i = 0; i < n; ++i) {
                  if (s[i] == '?') q.push_back(i);
            }
 
            int ans = 10;
            int sz = q.size();
            for (int i = 0; i < (1 << sz); ++i) {
                  string ss = s;
                  for (int j = 0; j < sz; ++j) {
                        if (i & 1 << j) ss[q[j]] = '1';
                        else ss[q[j]] = '0';
                  }
                  // int s1 = 0, s2 = 0;
                  // for (int j = 0; j < 
                  // debug(ss);
                  int p1[10], p2[10];
                  p1[0] = ss[0] == '1', p2[0] = 0;
                  for (int j = 1; j < 10; ++j) {
                        p1[j] = p1[j - 1];
                        p2[j] = p2[j - 1]; 
                        if (j % 2 == 0) p1[j] += ss[j] == '1';
                        else p2[j] += ss[j] == '1';
                  }
 
                  for (int j = 0; j < 10; ++j) {
                        int s1 = p1[j], s2 = p2[j];
                        if (s1 > s2) {
                              int need = s1 - s2;
                              int ext = 0;
                              for (int k = j + 1; k < 10; ++k) ext += (k % 2 == 1);
                              if (ext < need) {
                                    ans = min(ans, j + 1);
                                    break;
                              }
                        } else if (s2 > s1) {
                              int need = s2 - s1;
                              int ext = 0;
                              for (int k = j + 1; k < 10; ++k) ext += (k % 2 == 0);
                              if (ext < need) {
                                    ans = min(ans, j + 1);
                                    break;
                              }
                        } 
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