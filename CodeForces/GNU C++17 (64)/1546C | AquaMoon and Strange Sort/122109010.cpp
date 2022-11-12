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
            map <pair <int, int>, int> cnt1, cnt2;
            for (int i = 0; i < n; ++i) {
                  cnt1[{a[i], i % 2}]++;
            }
            sort(a.begin(), a.end());
            for (int i = 0; i < n; ++i) {
                  cnt2[{a[i], i % 2}]++;
            }
            map <int, int> done;
 
            bool works = true;
            for (int x : a) {
                  if (!done[x]) {
                        if (cnt1[{x, 0}] != cnt2[{x, 0}] || cnt1[{x, 1}] != cnt2[{x, 1}]) works = false;
                        done[x]++;
                  }
            }
 
            if (works) cout << "YES\n";
            else cout << "NO\n";
      }
 
      #ifdef Icry
            auto end = chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << chrono::duration_cast <chrono :: duration <double>> (end - begin).count() << " seconds]\n";  
      #endif
}