#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
using namespace std;
 
const int N = 510;
int a[N][N];
int n;
 
void rec(int i, int j, int val, int cnt) {
      if (!cnt) return;
      a[i][j] = val;
      if (i + 1 < n && a[i + 1][j] == -1) rec(i + 1, j, val, cnt - 1);
      else if (j - 1 >= 0 && a[i][j - 1] == -1) rec(i, j - 1, val, cnt - 1);
}
 
int main() {
      #ifdef Icry
            auto begin = chrono :: high_resolution_clock :: now();
      #endif
      ios_base :: sync_with_stdio(0);
      cin.tie(0);
 
      cin >> n;
      vector <int> p(n); for (int &x : p) cin >> x;
 
      memset(a, -1, sizeof a);
      for (int i = n - 1; i >= 0; --i) {
            rec(i, i, p[i], p[i]);
      }
 
      for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= i; ++j) {
                  cout << a[i][j] << ' '; 
            }
            cout << '\n';
      }
 
      #ifdef Icry
            auto end = chrono :: high_resolution_clock :: now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << chrono :: duration_cast <chrono :: duration <double>> (end - begin).count() << " seconds]\n";  
      #endif
}