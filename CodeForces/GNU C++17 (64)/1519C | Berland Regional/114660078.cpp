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
            vector <int> u(n); for (int &x : u) cin >> x;
            vector <int64_t> skill(n); for (auto &x : skill) cin >> x;
 
            map <int, vector <int64_t>> uni;
            for (int i = 0; i < n; ++i) {
                  uni[u[i]].push_back(skill[i]);
            }
 
            vector <int64_t> ans(n + 1, 0);
            for (auto &[x, v] : uni) {
                  sort(v.rbegin(), v.rend());
                  vector <int64_t> pref;
                  pref.push_back(0);
                  for (auto d : v) pref.push_back(pref.back() + d);
                  for (int j = 1; j <= (int) v.size(); ++j) ans[j] += pref[(int) v.size() - (int) v.size() % j];
            }
 
            for (int i = 1; i <= n; ++i) cout << ans[i] << ' ';
            cout << '\n';
      }
 
      #ifdef Icry
            auto end = chrono :: high_resolution_clock :: now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << chrono :: duration_cast <chrono :: duration <double>> (end - begin).count() << " seconds]\n";  
      #endif
}