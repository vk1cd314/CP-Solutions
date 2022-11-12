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
            set <int> s;
            int n; cin >> n;
            vector <int> a(n); for (int &x : a) cin >> x;
            for (int x : a) s.insert(x);
 
            while ((int) s.size() <= 300) {
                  vector <int> works;
                  for (int x : s) works.push_back(x);
                  set <int> cc = s;
                  for (int i = 0; i < (int) works.size(); ++i) {
                        for (int j = i + 1; j < (int) works.size(); ++j) {
                              s.insert(abs(works[i] - works[j]));
                        }
                  }
                  if (cc == s) break;
            }
 
            // debug(s);
            if ((int) s.size() <= 300) {
                  cout << "YES\n";
                  cout << s.size() << '\n';
                  for (int x : s) cout << x << ' ';
                  cout << '\n';
            } else cout << "NO\n";
      }
 
      #ifdef Icry
            auto end = chrono :: high_resolution_clock :: now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << chrono :: duration_cast <chrono :: duration <double>> (end - begin).count() << " seconds]\n";  
      #endif
}