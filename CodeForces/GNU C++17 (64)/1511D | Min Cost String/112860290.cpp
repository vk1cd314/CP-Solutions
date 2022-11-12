#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
using namespace std;
 
int n, k; 
string s;
map <string, int> cost;
 
void rec(int x) {
      if (x == n) {
            int cnt = 0;
            for (int i = 0; i + 1 < n; ++i) {
                  for (int j = i + 1; j + 1 < n; ++j) {
                        if (s[i] == s[j] && s[i + 1] == s[j + 1]) ++cnt;
                  }
            }
            cost[s] = cnt;
            return;
      }
      for (int j = 0; j < k; ++j) {
            s += char('a' + j);
            rec(x + 1);
            s.pop_back();
      }
}
 
int main() {
      #ifdef Icry
            auto begin = std::chrono::high_resolution_clock::now();
      #endif
      ios_base :: sync_with_stdio(0);
      cin.tie(0);
 
      cin >> n >> k;
      // rec(0);
      // // debug(cost);
      // int mi = INT_MAX;
      // for (auto [x, y] : cost) {
      //       mi = min(mi, y);
      // }
 
      // for (auto [x, y] : cost) {
      //       if (mi == y) {
      //             debug(x, mi);
      //             break;
      //       }
      // }
 
      string ans;
      // abacadaebcbdbe
      for (int i = 0; i < k; ++i) {
            ans += char('a' + i);
            for (int j = i + 1; j < k; ++j) {
                  ans += char('a' + i);
                  ans += char('a' + j);
            }
      }
 
      string ded;
      while ((int) ded.size() < n) ded += ans;
 
      for (int i = 0; i < n; ++i) cout << ded[i];
 
      #ifdef Icry
            auto end = std::chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << std::chrono::duration_cast <std::chrono::duration <double>>(end - begin).count() << " seconds]\n";  
      #endif
}