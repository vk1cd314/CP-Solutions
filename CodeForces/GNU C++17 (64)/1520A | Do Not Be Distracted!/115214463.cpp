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
            map <char, int> ss;
            for (char c : s) ss[c]++;
            vector <pair <char, int>> groups;
            groups.push_back({s[0], 1});
            for (int i = 1; i < n; ++i) {
                  if (groups.back().first == s[i]) groups.back().second++;
                  else {
                        groups.push_back({s[i], 1});
                  }
            }
 
            bool ok = true;
            for (auto [x, y] : groups) {
                  if (ss[x] != y) ok = false;
            }
 
            cout << (ok ? "YES\n" : "NO\n");
      }
 
      #ifdef Icry
            auto end = chrono :: high_resolution_clock :: now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << chrono :: duration_cast <chrono :: duration <double>> (end - begin).count() << " seconds]\n";  
      #endif
}