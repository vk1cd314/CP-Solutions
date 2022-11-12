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
            vector <int> a(n); for (int &x : a) cin >> x;
            map <int, int> cnt;
            for (int x : a) cnt[x]++;
            priority_queue <pair <int, int>> ded;
            for (auto [xx, dd] : cnt) ded.push({dd, xx});
            debug(ded);
            while ((int) ded.size() > 1) {
                  auto d1 = ded.top(); ded.pop();
                  auto d2 = ded.top(); ded.pop();
                  if (d1.first - 1 > 0) ded.push({d1.first - 1, d1.second});
                  if (d2.first - 1 > 0) ded.push({d2.first - 1, d2.second});
            }
            int sz = 0;
            while (!ded.empty()) sz += ded.top().first, ded.pop();
            cout << sz << '\n';
      }
 
      #ifdef Icry
            auto end = std::chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << std::chrono::duration_cast <std::chrono::duration <double>>(end - begin).count() << " seconds]\n";  
      #endif
}