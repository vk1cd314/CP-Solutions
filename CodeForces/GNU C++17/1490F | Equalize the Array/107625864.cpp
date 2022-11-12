#include <bits/stdc++.h>
 
using namespace std;
 
#ifdef SENDHELP
#include "debug.h"
#else
#define debug(args...)
#endif
 
int main() {
      #ifdef SENDHELP
            auto begin = std::chrono::high_resolution_clock::now();
      #endif
      ios_base :: sync_with_stdio(0);
      cin.tie(0);
 
      int t; cin >> t;
      while (t--) {
            int n; cin >> n;
            map <int, int> cnt;
            vector <int> a(n); for (int &x : a) cin >> x, cnt[x]++;
 
            vector <int> v;
            for (auto pp : cnt) v.push_back(pp.second);
            sort(v.begin(), v.end());
 
            int ans = 0;
            for (int i = 0; i < (int) v.size(); ++i) {
                  if (i == 0 || v[i] != v[i - 1]) ans = max(ans, ((int) v.size() - i) * v[i]);
            }
 
            cout << n - ans << '\n';
      }
 
      #ifdef SENDHELP
            auto end = std::chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << std::chrono::duration_cast <std::chrono::duration <double>>(end - begin).count() << " seconds]\n";  
      #endif
}