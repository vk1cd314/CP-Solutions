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
            vector <pair <char, int>> groups;
            groups.push_back({s[0], 1});
            for (int i = 1; i < n; ++i) {
                  if (s[i] == groups.back().first) groups.back().second++;
                  else {
                        groups.push_back({s[i], 1});
                  }
            }
 
            int sz = groups.size();
            vector <int64_t> dp1(sz, 0);
            vector <int64_t> pref(sz, 0);
            pref[0] = groups[0].first == '*' ? groups[0].second : 0;
            for (int i = 1; i < (int) sz; ++i) {
                  pref[i] = pref[i - 1];
                  if (groups[i].first == '*') pref[i] += groups[i].second;
            }
 
            dp1[0] = 0;
            for (int i = 1; i < sz; ++i) {
                  dp1[i] = dp1[i - 1];
                  if (groups[i].first == '*') dp1[i] += pref[i - 1] * groups[i - 1].second;
            }
 
            vector <int64_t> dp2(sz, 0);
            vector <int64_t> suff(sz, 0);
            suff[sz - 1] = groups[sz - 1].first == '*' ? groups[sz - 1].second : 0;
            for (int i = sz - 2; i >= 0; --i) {
                  suff[i] = suff[i + 1];
                  if (groups[i].first == '*') suff[i] += groups[i].second;
            }
 
            dp2[sz - 1] = 0;
            for (int i = sz - 2; i >= 0; --i) {
                  dp2[i] = dp2[i + 1];
                  if (groups[i].first == '*') dp2[i] += suff[i + 1] * groups[i + 1].second;
            }
 
            int64_t ans = LLONG_MAX;
            for (int i = 0; i < sz; ++i) {
                  if (groups[i].first == '*') ans = min(ans, dp1[i] + dp2[i]);
            }
 
            if (ans == LLONG_MAX) ans = 0;
            cout << ans << '\n';
      }
 
      #ifdef Icry
            auto end = chrono :: high_resolution_clock :: now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << chrono :: duration_cast <chrono :: duration <double>> (end - begin).count() << " seconds]\n";  
      #endif
}