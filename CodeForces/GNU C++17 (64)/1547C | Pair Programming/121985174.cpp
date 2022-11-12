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
            int k, n, m; cin >> k >> n >> m;
            vector <int> a(n); for (int &x : a) cin >> x;
            vector <int> b(m); for (int &x : b) cin >> x;
 
            int i = 0, j = 0;
            vector <int> tot;
            bool ok = true;
            while (3) {
                  if (i == n && j == m) break;
                  else if (i == n) {
                        tot.push_back(b[j++]);
                  } else if (j == m) {
                        tot.push_back(a[i++]);
                  } else if (a[i] < b[j]) {
                        tot.push_back(a[i++]);
                  } else tot.push_back(b[j++]);
            }
 
            int curr = k;
            for (int x : tot) {
                  if (!x) curr++;
                  else if (x > curr) ok = false;
            }
 
            if (!ok) cout << "-1";
            else for (int x : tot) cout << x << ' ';
            cout << '\n';
      }
 
      #ifdef Icry
            auto end = chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << chrono::duration_cast <chrono :: duration <double>> (end - begin).count() << " seconds]\n";  
      #endif
}