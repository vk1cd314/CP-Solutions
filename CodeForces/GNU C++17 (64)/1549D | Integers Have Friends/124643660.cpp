#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
using namespace std;
 
const int N = 2e5 + 10;
const int K = 22;
int64_t st[N][K], lg[N], a[N], b[N];
 
int64_t f(int64_t a, int64_t b) { return __gcd(a, b); }
 
void pre(int n) {
      for (int i = 0; i < n; ++i) st[i][0] = a[i];
 
      for (int j = 1; j < K; ++j) {
            for (int i = 0; i + (1 << j) <= n; ++i) {
                  st[i][j] = f(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
      }
}
 
int64_t query(int l, int r) {
      int j = lg[r - l + 1];
      return f(st[l][j], st[r - (1 << j) + 1][j]);
}
 
int main() {
      #ifdef Icry
            auto begin = chrono::high_resolution_clock::now();
      #endif
      ios_base::sync_with_stdio(0);
      cin.tie(0);
 
      lg[1] = 0;
      for (int i = 2; i < N; ++i) {
            lg[i] = lg[i >> 1] + 1;
      }
 
      int t; cin >> t;
      while (t--) {
            int n; cin >> n;
            memset(a, 0, sizeof a);
            for (int i = 0; i < n; ++i) cin >> b[i];  
            for (int i = 1; i < n; ++i) a[i - 1] = abs(b[i] - b[i - 1]);
            pre(n - 1);
            
            int ans = 1;
            int i = 0, j = 0;
            while (i + 1 < n) {
                  while (j < i + 1 && query(j, i) == 1) ++j;
                  ++i;
                  ans = max(ans, i - j + 1);
            }
 
            cout << ans << '\n';
      }
 
      #ifdef Icry
            auto end = chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << chrono::duration_cast <chrono :: duration <double>> (end - begin).count() << " seconds]\n";  
      #endif
}