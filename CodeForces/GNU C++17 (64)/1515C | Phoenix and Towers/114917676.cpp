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
      // ios_base :: sync_with_stdio(0);
      // cin.tie(0);
 
      int t; cin >> t;
      while (t--) {
            int n, m, x; cin >> n >> m >> x;
            vector <int> h(n); for (int &x : h) cin >> x;
            
            set <pair <int, int>> ss;
            for (int i = 0; i < n; ++i) ss.insert({h[i], i});
 
            debug(4444);
            set <pair <int, int>> ans;
            map <int, int> huh;
            for (int i = 0; i < m; ++i) {
                  auto it = ss.begin();
                  ans.insert({(*it).first, i});
                  huh[(*it).second] = i; 
                  ss.erase(it);
            }
            debug(5555);
 
 
            debug(3);
            bool ok = true;
            while (!ss.empty()) {
                  auto it = ss.rbegin();
                  auto it1 = ans.begin();
                  huh[(*it).second] = (*it1).second;
                  ans.insert({(*it).first + (*it1).first, (*it1).second});
                  ans.erase(it1);
                  ss.erase(--ss.end());
                  // if ((int) ans.size() == 1) continue;
                  auto it2 = ans.begin();
                  auto it3 = ans.rbegin();
                  if ((*it3).first - (*it2).first > x) ok = false;
            }
 
            if (!ok) cout << "NO\n";
            else {
                  cout << "YES\n";
                  for (int i = 0; i < n; ++i) {
                        cout << huh[i] + 1 << ' ';
                  }
                  cout << '\n';
            }
      }
 
      #ifdef Icry
            auto end = chrono :: high_resolution_clock :: now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << chrono :: duration_cast <chrono :: duration <double>> (end - begin).count() << " seconds]\n";  
      #endif
}