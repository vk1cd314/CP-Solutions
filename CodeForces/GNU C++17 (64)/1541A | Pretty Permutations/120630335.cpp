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
            vector <int> a(n); iota(a.begin(), a.end(), 1);
            if (n % 2) {
                  swap(a[0], a[2]);
                  swap(a[1], a[2]);
                  for (int i = 3; i + 1 < n; i += 2) swap(a[i], a[i + 1]);
                  for (int x : a) cout << x << ' ';
                  cout << '\n';
            } else {
                  for (int i = 0; i + 1 < n; i += 2) swap(a[i], a[i + 1]);
                  for (int x : a) cout << x << ' ';
                  cout << '\n';
            }
      }
 
      #ifdef Icry
            auto end = chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << chrono::duration_cast <chrono :: duration <double>> (end - begin).count() << " seconds]\n";  
      #endif
}