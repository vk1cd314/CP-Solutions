#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
using namespace std;
 
set <int> nums;
int n, m;
void rec(int i, int j,int curr) {
      if (i == n && j == m) {
            nums.insert(curr);
            return;
      }
      if (i + 1 <= n) rec(i + 1, j, curr + j);
      if (j + 1 <= m) rec(i, j + 1, curr + i);
}
 
int main() {
      #ifdef Icry
            auto begin = chrono :: high_resolution_clock :: now();
      #endif
      ios_base :: sync_with_stdio(0);
      cin.tie(0);
 
      int t; cin >> t;
      while (t--) {
            int k; cin >> n >> m >> k;
            // int val1 = m - 1 + ((n - 1) * (n - 2)) / 2;
            // int val2 = n - 1 + ((m - 1) * (m - 2)) / 2;
 
            int baal = m - 1 + (n - 1) * m;
            cout << (k == baal ? "YES\n" : "NO\n");
 
            // if (k == val1 || k == val2) cout << "Yes\n";
            // else cout << "No\n";
            // rec(1, 1, 0);
            // debug(nums);
            // always trust your gut ig 
      }
 
      #ifdef Icry
            auto end = chrono :: high_resolution_clock :: now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << chrono :: duration_cast <chrono :: duration <double>> (end - begin).count() << " seconds]\n";  
      #endif
}