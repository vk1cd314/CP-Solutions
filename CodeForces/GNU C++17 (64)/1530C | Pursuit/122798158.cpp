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
            vector <int> a(n); for (int &x : a) cin >> x;
            vector <int> b(n); for (int &x : b) cin >> x;
            map <int, int> a1, b1;
            for (int x : a) a1[x]++;
            for (int x : b) b1[x]++;
            int ans = 0;
            while (3) {
                  int sz = n + ans;
                  int take = sz - sz / 4;
                  int s1 = 0, s2 = 0;
                  for (auto it = a1.rbegin(); it != a1.rend(); ++it) {
                        if (take - it->second >= 0) take -= it->second, s1 += it->first * it->second;
                        else {
                              s1 += it->first * take;
                              take = 0;
                              break;
                        }
                  }
                  take = sz - sz / 4;
                  for (auto it = b1.rbegin(); it != b1.rend(); ++it) {
                        if (take - it->second >= 0) take -= it->second, s2 += it->first * it->second;
                        else {
                              s2 += it->first * take;
                              take = 0;
                              break;
                        }
                  }
 
                  if (s1 >= s2) break;
                  ans++;
                  a1[100]++, b1[0]++;
            }
 
            cout << ans << '\n';
 
      }
 
      #ifdef Icry
            auto end = chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << chrono::duration_cast <chrono :: duration <double>> (end - begin).count() << " seconds]\n";  
      #endif
}