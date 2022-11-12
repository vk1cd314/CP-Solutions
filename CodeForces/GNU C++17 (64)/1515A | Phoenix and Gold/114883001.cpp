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
            int n, x; cin >> n >> x;
            vector <int> w(n); for (int &x : w) cin >> x;
            
            int sum = accumulate(w.begin(), w.end(), 0);
            if (sum == x) {
                  cout << "NO\n";
                  continue;
            }
 
            int mx = *max_element(w.begin(), w.end());
            if (mx > x) {
                  sort(w.rbegin(), w.rend());
                  cout << "YES\n";
                  for (int x : w) cout << x << ' ';
                  cout << '\n';
                  continue;
            }
 
            vector <int> ops;
            int curr = 0;
            map <int, int> done;
            while (true) {
                  bool ok = true;
                  for (int i = 0; i < n; ++i) ok &= done[w[i]];
                  if (ok) break;
                  for (int i = n - 1; i >= 0; --i) {
                        if (!done[w[i]] && curr + w[i] != x) ops.push_back(w[i]), done[w[i]]++, curr += w[i];
                  }
            }
            
            curr = 0;
            for (int y : ops) {
                  curr += y;
                  assert(curr != x);
            }
 
            cout << "YES\n";
            for (int y : ops) cout << y << ' ';
            cout << '\n';
      }
 
      #ifdef Icry
            auto end = chrono :: high_resolution_clock :: now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << chrono :: duration_cast <chrono :: duration <double>> (end - begin).count() << " seconds]\n";  
      #endif
}